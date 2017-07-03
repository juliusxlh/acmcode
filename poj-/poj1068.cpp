#include <stdio.h>
#include <iostream>
#pragma warning(disable:4996)
using namespace std;
int main()
{
	int n, case_num, pre, m, h[100];
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	cin >> case_num;
	for (int i = 0; i < case_num; i++) {
		cin >> n;	
		memset(h, 0, 100 * sizeof(int));
		pre = 0;
		int now = 0;
		for (int j = 0; j < n; j++) {
			cin >> m;
			if (m != pre) {
				now += m - pre-1;
				h[now] += 1;
				if (j != 0) cout << ' ' << 1; else cout << 1;
			}
			else {
				if (j != 0)cout << ' ' << h[now] + 1; else cout << h[now] + 1;
				now--;
				h[now]+=h[now+1]+1;
				h[now + 1] = 0;
			}
			pre = m;
		}
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
}