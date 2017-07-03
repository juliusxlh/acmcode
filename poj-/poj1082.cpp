#include <stdio.h>
#include <iostream>
#pragma warning (disable:4996)
using namespace std;
bool calendar[110][14][33];
const int monthsday[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
bool check(int x, int y, int z)
{
	if (x == 2001 && y > 11) return false;
	if (x == 2001 && y == 11 && z > 4) return false;
	if (y != 2 && z > monthsday[y - 1]) return false;
	if (y == 2 && ((x%4!=0&&z>28)||(x%400==0&&z>29)||(x%400!=0&&x%100==0&&z>28)||(x%4==0&&x%100!=0&&z>29)))return false;
	return true;
}
int main()
{
	memset(calendar, 1, sizeof(calendar));
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	for (int i = 2001; i >= 1900; i--) {
		for (int j = 12; j >= 1; j--) {
			for (int k = 31; k >= 1; k--) {
				if (check(i, j, k)) {
					bool x, y;
					if (check(i, j + 1, k))x = !calendar[i - 1900][j + 1][k]; else {
						if (j == 12) x = !calendar[i - 1900][1][k]; else
							x = false;
					}
					if (check(i, j, k+1))y = !calendar[i - 1900][j][k+1]; else {
						if (j != 12) y = !calendar[i - 1900][j + 1][1]; else y = !calendar[i - 1900+1][1][1];
					}
					if (x || y) calendar[i - 1900][j][k] = true; else
						calendar[i - 1900][j][k] = false;
				}
			}
		}
	}
	int cases;
	cin >> cases;
	while (cases--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (calendar[a - 1900][b][c]) cout << "YES" << endl; else cout << "NO" << endl;
	}
	fclose(stdin);
	fclose(stdout);
}