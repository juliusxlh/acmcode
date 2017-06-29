#include <stdio.h>
#include <iostream>
#pragma warning(disable:4996)
using namespace std;
int n, ans[30], now[30],t[30][300],dis[30];
void foud(int x,int y,int z)
{
	now[x] = t[x][y];
	if (x == 0) {
		now[x] += z-t[x][y];
		return;
	}
	foud(x-1,y-t[x][y]-dis[x-1],z-t[x][y]-dis[x-1]);
}
void cop()
{
	for (int i = 0; i != n; i++) {
		if (now[i] > ans[i]) {
			for (int j = 0; j != n; j++) ans[j] = now[j];
			memset(now, 0, sizeof(now));
		}
		else if (now[i] < ans[i]) break;
	}
}
int main()
{
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	int h, f[30], d[30], p[30][300];
	bool  bo[25][300];
	while (cin >> n, n != 0) {
		cin >> h;
		memset(bo, 0, sizeof(bo));
		memset(p, 0, sizeof(p));
		memset(t, 0, sizeof(t));
		bo[0][0] = true;
		for (int i = 0; i != n; i++) {
			cin >> f[i];
			if (f[i] < 0) f[i] = 0;
		}
		for (int i = 0; i != n; i++) cin >> d[i];
		for (int i = 0; i != n - 1; i++) cin >> dis[i];
		for (int i = 0; i != n; i++) {
			if (i == 0) {
				int st = f[0];
				int num = 0;
				while (st > 0) {
					num++;
					if (num > h * 12) break;
					p[0][num] = p[0][num - 1] + st;
					t[0][num] = num;
					bo[0][num] = true;
					st -= d[0];
				}
			}
			else {
				for (int j = h * 12; j >= dis[i - 1]; j--) {
					p[i][j] = p[i - 1][j - dis[i - 1]];
					bo[i][j] = bo[i - 1][j - dis[i - 1]];
				}
				for (int j = h * 12; j >= 0; j--) {
					if (bo[i][j]) {
						int st = f[i];
						int num = j + 1;
						while (st > 0 && num <= h * 12) {
							if (p[i][num - 1] + st <= p[i][num]) break;
							p[i][num] = p[i][num - 1] + st;
							t[i][num] = num - j;
							bo[i][num] = true;
							st -= d[i];
							num++;
						}
					}
				}
			}
		}
		int maxi = 0;
		int maxj = 0;
		int mas = 0;
		memset(ans, 0, sizeof(ans));
		memset(now, 0, sizeof(now));
		for (int i = h * 12; i > 0; i--)
			for (int j = 0; j < n; j++) {
				if (p[j][i] > mas) {
					mas = p[j][i];
					maxj = i;
					maxi = j;
				}
			}
		foud(maxi, maxj,h*12);
		cop();
		for (int i = h * 12; i > 0; i--)
			for (int j = 0; j < n; j++) {
				if (p[j][i] == mas && !(maxi == i&&maxj == j)&&bo[j][i]) {
					foud(j, i,h*12);
					cop();
				}
			}
		for (int i = 0; i != n; i++) {
			if (i != 0)cout << ", ";
			cout << ans[i]*5;
		}
		cout << endl << "Number of fish expected: " << mas << endl <<endl;
	}
	fclose(stdin);
	fclose(stdout);
}