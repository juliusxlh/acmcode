#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
#pragma warning (disable:4996)
using namespace std;
char str[10005][20];
char s[20];
int ans[10005];
int sizes=0;
bool bo[10005];
int  cop(int x)
{
	int l1 = strlen(s);
	int l2 = strlen(str[x]);
	if ((l1-l2)!=1&&(l1-l2)!=0&&(l1-l2)!=-1) {
		return false;
	}
	int st = 0;
	int ed = 0;
	bool flags = true;
	while (true) {
		if (s[st] == 0 && str[x][ed] == 0) {
			if (l1 == l2&&flags) return 2; else return 1;
		}
		else if (s[st] == 0 || str[x][ed] == 0) {
			if (flags) return 1; else return 0;
		}
		if (s[st] == str[x][ed]) {
			st++;
			ed++;
		}
		else {
			if (flags) {
				if (l1 == l2) {
					st++;
					ed++;
					flags = false;
				}else
				if (l1 < l2) {
					ed++;
					flags = false;
				}
				else {
					st++;
					flags = false;
				}
			}
			else return false;
		}
	}
}
int main()
{
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	int sum = 0;
	while (cin >> str[sum], str[sum][0] != '#') {
		sum++;
	}
	while (cin >> s, s[0] != '#') {
		sizes = 0;
		memset(bo, 0, 10005 * sizeof(bool));
		bool flag = true;;
		for (int i = 0; i != sum; i++) {
			int ret = cop(i);
			if (ret == 2) {
				flag = false;
				cout << s << " is correct"<<endl;
				break;
			}
			else if (ret){
				ans[sizes] = i;
				sizes++;
			}
		}
		if (!flag) continue;
		printf("%s:", s);
		for (int i = 0; i != sizes; i++) {
			printf(" %s", str[ans[i]]);
		}
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
}