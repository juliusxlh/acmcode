#include <stdio.h>
#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
struct point {
	int x;
	int y;
};
int f[100][4];
int n;
void inputthread() {
	cin >> n;
	for (int i = 0; i != n; i++) {
		cin >> f[i][0] >> f[i][1] >> f[i][2] >> f[i][3];
	}
	f[n][0] = 0;
	f[n][1] = 0;
	f[n][2] = 100;
	f[n][3] = 0;
	f[n + 1][0] = 0;
	f[n + 1][1] = 0;
	f[n + 1][2] = 0;
	f[n + 1][3] = 100;
	f[n + 2][0] = 0;
	f[n + 2][1] = 100;
	f[n + 2][2] = 100;
	f[n + 2][3] = 100;
	f[n + 3][0] = 100;
	f[n + 3][1] = 100;
	f[n + 3][2] = 100;
	f[n + 3][3] = 0;
}
void FindTheCrossPoint()
{
	for (int i = 0; i != n + 4; i++) {
		for (int j = 0; j != n + 4; j++) {

		}
	}
}
int main()
{
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	inputthread();
	FindTheCrossPoint();
	fclose(stdin);
	fclose(stdout);
}