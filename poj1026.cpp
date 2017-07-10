#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdio>
#pragma warning (disable:4996)
using namespace std;
struct belong {
	int x;
	int y;
};
belong q[201];
int main()
{
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	int n;
	while (cin>>n,n!=0) {
		vector<int> p[205];
		int f[200];
		bool flag[201];
		memset(flag, true,sizeof(flag));
		for (int i = 0; i != n; i++) cin >> f[i];
		for (int i = 0; i != n; i++) if (flag[i]){
			flag[i] = false;
			p[i].push_back(i + 1);
			int pre = 0;
			q[i].x = i;
			q[i].y = 0;
			while (f[p[i][pre] - 1] != i + 1) {
				flag[f[p[i][pre] - 1]-1] = false;
				q[f[p[i][pre] - 1]-1].x = i;
				q[f[p[i][pre] - 1]-1].y = pre+1;
				p[i].push_back(f[p[i][pre] - 1]);
				pre++;
			}
		}
		while (true) {
			char ans[205];
			memset(ans, 0, sizeof(ans));
			int k;
			cin >> k;
			if (k == 0) break;
			char ch[205];
			getchar();
			gets_s(ch,201);
			string s(ch);
			int len = s.length();
			for (int i = 0; i != n; i++) {
				int x = q[i].x;
				int y = q[i].y;
				int size = (k + y) % p[x].size();
				if (i >= len) ans[p[x][size] - 1] = ' '; else ans[p[x][size] - 1] = s[i];
			}
			ans[n] = 0;
			printf("%s\n",ans);
		}
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
}