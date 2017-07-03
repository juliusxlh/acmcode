#include <stdio.h>
#include <iostream>
#pragma warning(disable:4996)
using namespace std;
int f[6],p[65000];
int main()
{
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	int num = 0, dest = 0;
	while (cin >> f[0] >> f[1] >> f[2] >> f[3] >> f[4] >> f[5]) {
		memset(p, 0, 65000 * sizeof(int));
		num++;
		if (f[0] == 0 && f[1] == 0 && f[2] == 0 && f[3] == 0 && f[4] == 0 && f[5] == 0) break;
		int sum = 0;
		for (int i = 0; i < 6; i++) {
			sum += (i + 1)*f[i];
		}
		if (sum % 2 != 0) {
			cout << "Collection #" << num << ':' << endl;
			cout << "Can't be divided." << endl << endl;
			continue;
		}
		else dest = sum / 2;
		p[0] = 1;
		for (int i = 0; i < 6; i++) {
			for (int j = dest; j >= 0; j--) {
				if (p[j]) {
					for (int k = 1; k <= f[i]; k++) {
						if (j + k*(i + 1) > dest) break;
						if (p[j+k*(i+1)]) break;
						p[j + k*(i + 1)] = i + 1;
					}
				}
			}
			}
		if (p[dest] != 0) {
			cout << "Collection #" << num << ':' << endl;
			cout << "Can be divided." << endl << endl;
		}
		else {
			cout << "Collection #" << num << ':' << endl;
			cout << "Can't be divided." << endl << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
}