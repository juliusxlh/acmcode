#include <stdio.h>
#include <iostream>
#pragma warning (disable:4996)
using namespace std;
int main()
{
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	int n;
	cin >> n;
	int st = 2;
	int now = 0;
	int f[100];
	memset(f, 0, sizeof(f));
	while (n >= st) {
		n = n - st;
		f[now] = st;
		now++;
		st++;
	}
	for (int i = now - 1; i >= 0; i--) {
		if (!n) break;
		f[i]++;
		n--;
	}
	if (n) f[now==0?0:now - 1]++;
	for (int i = 0; i != now; i++) {
		if (!i) cout << f[i]; else cout << ' ' << f[i];
	}
	fclose(stdout);
	fclose(stdout);
}