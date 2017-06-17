#include <stdio.h>
#include <iostream>
#include <string>
#pragma	 warning (disable:4996)
using namespace std;
string head[200];
int main()
{
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	string s;
	head[0] = "http://www.acm.org/";
	int now = 0;
	int st = 0;
	while (cin >> s) {
		if (s == "QUIT") break;
		if (s == "VISIT") {
			cin >> s;
			now = st + 1;;
			st++;
			head[now] = s;
			cout << s << endl;
		}
		if (s == "FORWARD") {
			if (st==now) cout << "Ignored"<<endl;
			else {
				st++;
				cout << head[st] << endl;
			}
		}
		if (s == "BACK") {
			if (st == 0) cout << "Ignored" << endl;
			else {
				st--;
				cout << head[st] << endl;
			}
		}

	}
	fclose(stdin);
	fclose(stdout);
}