#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;
struct MyStruct
{
	int time;
	int pro;
	int stou;
};
bool cop(MyStruct x, MyStruct y)
{
	if (x.time < y.time) return true;
	if (x.time == y.time &&x.stou < y.stou) return true;
	return false;
}
MyStruct gan[200];
int main()
{
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	int n, k, t,p[105][105],h[10000];
	memset(gan, 0, sizeof(gan));
	cin >> n >> k >> t;
	for (int i = 1; i <= n; i++) cin >> gan[i].time;
	for (int i = 1; i <= n; i++) cin >> gan[i].pro;
	for (int i = 1; i <= n; i++) cin >> gan[i].stou;
	sort(gan + 1, gan + n + 1,cop);
	int st = 1;
	for (int i = 2; i <= n; i++) {
		if (gan[i].time == gan[st].time&&gan[i].stou == gan[st].stou) {
			gan[st].pro += gan[i].pro;
			gan[i].pro = 0;
		}
		else st = i;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i != j&&gan[j].time - gan[i].time >= abs(gan[j].stou - gan[i].stou)) {
				p[i][j] = gan[j].pro;
			}
		}
	}
	st = 0;
	int ed = 0;
	int ans[105];
	memset(ans, 0, sizeof(ans));
	bool bo[105];
	memset(bo, 1, sizeof(bo));
	bo[0] = 0;
	h[0] = 0;
	while (st <= ed) {
		for (int i=0;i<=n;i++)
			if (p[h[st]][i] + ans[h[st]] > ans[i]&&p[h[st]][i]) {
				ans[i] = ans[h[st]] + p[h[st]][i];
				if (bo[i]) {
					ed++;
					bo[i] = 0;
					h[ed] = i;
				}
			}
		bo[h[st]] = 1;
		st++;
	}
	int max = 0;
	for (int i = 1; i <= n; i++) if (ans[i] > max) max = ans[i];
	cout << max << endl;
	fclose(stdin);
	fclose(stdout);
}