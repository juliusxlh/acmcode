#include <stdio.h>
#include <string>
#include <iostream>
#pragma warning(disable:4996)
using namespace std;
string answer;
int main()
{
	int n, m,flag,i,f[30][30],inf[30],p[30],x;
	bool bl[30],bol[30];
	char a, b, c;
	flag = 0;
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	while (cin >> n >> m, (n != 0) || (m != 0)) {
		memset(bol, false, 30 * sizeof(bool));
		memset(inf, 0, 30 * sizeof(int));
		x = true;
		memset(f, 0, 900*sizeof(int));
		memset(bl, true, 30 * sizeof(bool));
		for (i = 0; i < m; i++) {
			cin >> a >> b >> c;
			answer = "";
			bol[a - 'A'] = true;
			bol[c - 'A'] = true;
			if (a == c) {
				flag = 1;
				goto close;
			}
			else {
				if (f[a - 'A'][c - 'A'] == 0) inf[c - 'A']++;
				f[a - 'A'][c - 'A'] = 1;
			}
			int sp = 0;
			for (int j = 0; j < 26; j++) if (bol[j]) sp++;
			for (int j = 0; j < 26; j++) { 
				p[j] = inf[j]; 
				bl[j] = bol[j];
			}
			bool flags = true;
			if (sp != n) flags = false;
			while (true) {
				int sum = 0;
				bool fl = false;
				for (int j = 0; j < 26; j++) if (p[j] == 0&&bl[j]) sum++;
				if (sum > 1) flags = false;
				for (int j=0;j<26;j++)
					if (p[j] == 0 && bl[j]) {
						sp--;
						answer += char(j + 'A');
						bl[j] = false;
						fl = true;
						for (int k = 0; k < 26; k++)
							if (f[j][k] == 1) p[k]--;
						break;
					}
				if (!fl) break;
			}
			if (sp) {
				flag = 1;
				goto close;
			}
			if (sp == 0 && flags) {
				flag = 2;
				goto close;
			}
		}
		flag = 3;
	close:
		switch (flag)
		{
		case 1: {
			cout << "Inconsistency found after " << i+1 << " relations."<<endl;
			for (int j = i + 1; j < m; j++) cin >> a >> b >> c;
			break;
		}
		case 2: {
			cout << "Sorted sequence determined after " << i+1 << " relations: " << answer<<'.'<<endl;
			for (int j = i + 1; j < m; j++) cin >> a >> b >> c;
			break;
		}
		case 3: {
			cout << "Sorted sequence cannot be determined."<<endl;
			break;
		}
		}
	}

	fclose(stdin);
	fclose(stdout);
}