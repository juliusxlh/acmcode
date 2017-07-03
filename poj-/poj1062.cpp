#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#pragma warning(disable:4996)
struct goods {
	int x;
	int y;
};
using namespace std;
goods f[110];
vector<goods> p[110];
int h[10000],ans[110];
int main()
{
	int n, m;
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> f[i].x >> f[i].y >> k;
		for (int j = 0; j != k; j++) {
			goods a;
			cin >> a.x >> a.y;
			p[i].push_back(a);
		}
	}
	int mincost = 0x7fffffff;
	for (int k = 1; k <= n; k++) {
		if (f[1].y<f[k].y || f[1].y>f[k].y + m) continue;
		int st = 0;
		int ed = 0;
		bool bo[110],visit[110];
		memset(visit, true, sizeof(visit));
		for (int j = 1; j <= n; j++) { if (f[j].y >= f[k].y&&f[j].y <= f[k].y + m) bo[j] = 1; else bo[j] = 0; }
		h[st] = 1;
		memset(ans,-1,sizeof(ans));
		visit[1] = false;
		ans[1] = 0;
		while (st <= ed) {
			for (int i = 0; i != p[h[st]].size(); i++) {
				if (bo[p[h[st]][i].x]&&(ans[h[st]]+p[h[st]][i].y<ans[p[h[st]][i].x]|| ans[p[h[st]][i].x]==-1)) {
					ed++;
					h[ed] = p[h[st]][i].x;
					ans[p[h[st]][i].x] = ans[h[st]] + p[h[st]][i].y;
					visit[h[ed]] = false;
				}
			}
			visit[h[st]] = true;
			st++;
		}
		for (int i = 1; i <= n; i++) if (ans[i]!=-1&&ans[i]+f[i].x < mincost) mincost = ans[i] + f[i].x;
	}
	cout << mincost << endl;
	fclose(stdin);
	fclose(stdout);
}