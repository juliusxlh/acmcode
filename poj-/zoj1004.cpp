#include <stdio.h>
#include <iostream>
#include <string>
#pragma warning (disable:4996)
using namespace std;
string s1, s2,ans;
char head[2000];
void dfs(int x, int y,int deep)
{
	if (y == s2.size()) {
		
		cout << ans << endl;
		return;
	}
	if (x != s1.size()) {
		ans = ans +  'i'+' ';
		head[deep + 1] = s1[x];
		dfs(x + 1, y, deep + 1);
		ans = ans.erase(ans.size() - 2, 2);
	}
	if (deep!=0&&head[deep] == s2[y]) {
		char a = head[deep];
		ans = ans + 'o' + ' ';
		dfs(x, y + 1, deep - 1);
		head[deep] = a;
		ans = ans.erase(ans.size() - 2, 2);
	}
}
int main()
{
	freopen("zoj.in", "r", stdin);
	freopen("zoj.out", "w", stdout);
	int sum = 0;
	while (cin >> s1 >> s2) {
		sum++;
		head[0] = ' ';
		cout << '[' << endl;
		dfs(0, 0, 0);
		cout << ']'<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
