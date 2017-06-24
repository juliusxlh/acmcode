#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#pragma warning (disable:4996)
using namespace std;
int f[100],p[100];
int main()
{
	freopen("poj.in","r",stdin);
	freopen("poj.out", "w", stdout);
	string s;
	while (cin >> s) {
		memset(f, 0, sizeof(f));
		int len = s.size();
		for (int i = 0; i != len; i++) {
			f[i] = s[len-i-1] - '0';
		}
		bool bo = true;
		for (int i = 2; i <= len; i++) {
			memset(p, 0, sizeof(p));
			int s1 = 0, m = 0;
			bool flags = true;
			for (int k = 0; k != 100; k++) {
				s1 = (f[k] * i + m);
				if (k >= len&&s1 != 0) { cout << s << " is not cyclic" << endl; flags = false; bo = false; }
				p[k] = s1 % 10;
				m = s1 / 10;
			}
			if (!flags) break;
			for (int j = 0; j != len; j++) {
				bool flag = true;
				if (p[j] == f[0]) {
					int k = 0;
					while (k!=len) {
						if (p[(j + k) % len] != f[k]) {
							flag = false;
							break;
						}
						++k;
					}
					if (flag) {
						flags = false;
						break;
					}
				}
			}
			if (flags) { cout << s << " is not cyclic" << endl; bo = false; break; }
		}
		if (bo) cout << s << " is cyclic" << endl;
	}
	fclose(stdin);
	fclose(stdout);
}