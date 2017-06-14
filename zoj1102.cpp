#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
const int num[10][7] = { { 1,1,1,0,1,1,1 },{ 0,0,1,0,0,1,0 },{ 1,0,1,1,1,0,1 },{ 1,0,1,1,0,1,1 },{ 0,1,1,1,0,1,0 },{ 1,1,0,1,0,1,1 }
,{ 1,1,0,1,1,1,1 },{ 1,0,1,0,0,1,0 },{ 1,1,1,1,1,1,1 },{ 1,1,1,1,0,1,1 } };
int main()
{
	int a, l, n, i, j, lmax, rmax;
	string s1;
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	while (1) {
		cin >> l >> n;
		if (l == 0 && n == 0) break;
		stringstream ss;
		ss << n;
		ss >> s1;
		lmax = l * 2 + 3;
		rmax = s1.size()*(l + 3);
		for (i = 0; i < lmax; i++) {
			for (j = 0; j < rmax; j++) {
				a = s1[j / (l + 3)] - '0';
				if (j % (l + 3) == 0 && (i != 0 && i != lmax - 1 && i != l + 1)) {
					if (i < l + 1 && num[a][1] == 1) cout << '|'; else
						if (i > l + 1 && num[a][4] == 1) cout << '|'; else cout << ' ';
				}
				else
					if (j % (l + 3) == l + 1 && (i != 0 && i != lmax - 1 && i != l + 1)) {
						if (i < l + 1 && num[a][2] == 1) cout << '|'; else
							if (i > l + 1 && num[a][5] == 1) cout << '|'; else cout << ' ';
					}
					else
						if (i == 0 && j % (l + 3) != 0 && j % (l + 3) < l + 1) {
							if (num[a][0] == 1) cout << '-'; else cout << ' ';
						}
						else
							if (i == lmax - 1 && j % (l + 3) != 0 && j % (l + 3) < l + 1) {
								if (num[a][6] == 1) cout << '-'; else cout << ' ';
							}
							else
								if (i == l + 1 && j % (l + 3) != 0 && j % (l + 3) < l + 1) {
									if (num[a][3] == 1) cout << '-'; else cout << ' ';
								}
								else cout << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
}