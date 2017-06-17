#include <stdio.h>
#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
int main()
{
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	int n, k, m, f[2000], g[2000];
	bool bo[2][2000];
	memset(bo,true,sizeof(bo));
	cin >> n >> k;
	for (int i = 0; i != k;i++) {
		cin >> m;
		for (int j = 0; j != 2 * m; j++) { 
			cin >> f[j]; 
			g[j] = f[j];
		}
		sort(g, g + 2 * m);
		char ch;
		cin >> ch;
		if (ch == '=') {
			for (int j = 0; j != 2 * m; j++) {
				bo[0][f[j]] = false;
				bo[1][f[j]] = false;
			}
		}
		else
				if (ch == '<') {
					int k = 0;
					for (int j = 1; j <= n; j++) {
						if (g[k] == j) k++; else {
							bo[0][j] = false;
							bo[1][j] = false;
						}
					}
					for (int j = 0; j != m; j++) {
						bo[0][f[j]] = false;
						bo[1][f[j + m]] = false;
					}
				}
				else {
					int k = 0;
					for (int j = 1; j <= n; j++) {
						if (g[k] == j) k++; else {
							bo[0][j] = false;
							bo[1][j] = false;
						}
					}
					for (int j = 0; j != m; j++) {
						bo[1][f[j]] = false;
						bo[0][f[j + m]] = false;
					}
				}
	}
	int l = -1, r = -1;
	bool bl = true, br = true;
	for (int i = 1; i <= n; i++) {
		if (bo[0][i]) {
			if (l == -1) l = i; else bl = false;
		}
		if (bo[1][i]) {
			if (r == -1) r = i; else br = false;
		}
	}
	if (bl&&l != -1&&!(br&&r != l&&r!=-1)) cout << l; else if (br&&r != -1&&!(bl&&l != r&&l!=-1)) cout << r; else cout << 0;
	fclose(stdin);
	fclose(stdout);
}