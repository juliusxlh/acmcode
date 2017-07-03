#include <stdio.h>
#include <iostream>
#pragma warning(disable:4996)
using namespace std;
int main()
{
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	int n,f[200][200],sum[200][200];
	cin >> n;
 	memset(sum, 0, 40000 * sizeof(int));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) { 
			cin >> f[i][j]; 
			sum[i][j] = f[i][j] + sum[i-1][j];
		}
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int now = 0;
			for (int k = 1; k <= n; k++) {
				if (now + sum[j][k] - sum[i - 1][k] > 0) now += sum[j][k] - sum[i - 1][k]; else now = 0;
				if (now > answer) answer = now;
			}
		}
	}
	cout << answer;
	fclose(stdin);
	fclose(stdout);
}
