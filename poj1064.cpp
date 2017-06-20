#include <stdio.h>
#include <iostream>
#include <math.h>
#include <iomanip>
#pragma warning (disable:4996)
using namespace std;
int f[10005], n, k;
int CalK(int x)
{
	int sum = 0;
	for (int i = 0; i != n; ++i) {
		sum += (f[i]/x);
	}
	return sum;
}
int main()
{
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	int a, b;
	char ch;
	cin >> n >> k;
	for (int i = 0; i != n; i++) {
		cin >> a>>ch>>b;
		f[i] = a*100+b;
	}
	int l = 0;
	int r = 10000000;
	int mid = (l + r +1) / 2;
	while (l < r) {
		if (CalK(mid) < k) {
			r = mid - 1;
			mid = (l + r +1) / 2;
		}
		else {
			l = mid ;
			mid = (l + r +1) / 2;
		}
	}
	if (mid < 100) cout << "0." << setw(2) << setfill('0') << mid; else cout << mid / 100 << '.' << setw(2) << setfill('0') << mid % 100;
	fclose(stdin);
	fclose(stdout);
}