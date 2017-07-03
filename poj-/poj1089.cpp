#include <stdio.h>
#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
struct interval {
	int x;
	int y;
};
bool cop(interval x, interval y)
{
	return x.x < y.x;
}
int main()
{
	int n;
	interval f[10000];
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	cin >> n;
	if (n != 0) {
		for (int i = 0; i != n; i++) cin >> f[i].x >> f[i].y;
		sort(f, f + n, cop);
		int st = f[0].x;
		int ed = f[0].y;
		for (int i = 0; i != n; i++) {
			if (f[i].x > ed) {
				cout << st << ' ' << ed << endl;
				st = f[i].x;
				ed = f[i].y;
			}
			else {
				if (f[i].y > ed) ed = f[i].y;
			}
		}
		cout << st << ' ' << ed << endl;
	}
	fclose(stdin);
	fclose(stdout);
}