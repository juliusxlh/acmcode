#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#pragma warning(disable:4996)
using namespace std;
int main()
{
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	int cases,n;
	long long des;
	string s;
	while (cases) {
		cases--;
		cin >> n;
		cin >> s;
		cin >> des;
		bool flag;
		if (des < 0) flag = false; else flag = true;
		int len = 0,f[100];
		while (des) {
			f[len] = des % 2;
			len++;
			des/= 2;
		}
		if (flag) {
			string s1(s);
			string ans = "";
			for (int i = len - 1; i >= 0; i++) {
				if (f[i] == 1) {

				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
}