#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#pragma warning(disable:4996)
using namespace std;
string path[100];
string ivention(string s)//求下一个string
{
	int num[10];
	memset(num, 0, 10 * sizeof(int));
	for (int i = 0; i != s.size(); i++){
		num[s[i] - '0']++;
    }
	string next="",ss="";
	for (int i = 0; i != 10; i++) {
		if (num[i] != 0) {
			ss = "";
			if (num[i] >= 10) {
			 ss = ss+char(num[i] / 10 + '0') + char(num[i] % 10 + '0');
			}
			else ss = ss + char(num[i] + '0');
			next +=ss;
			next = next +char(i + '0');
		}
	}
	return next;
}
int  check(int x)
{
	for (int i = x - 1; i >= 0; i--)
		if (path[x] == path[i]) return (x - i);
	return 0;
}
int main()
{
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	string s;
	while (cin >> s) {
		if (s == "-1") break;
		path[0] = s;
		int steps = 0;
		while (1) {
			steps++;
			path[steps] = ivention(path[steps-1]);
			if (steps == 1 && path[0] == path[steps]) {
				cout << s << " is self-inventorying"<<endl;
				break;
			}else
				if (path[steps-1] == path[steps]) {
					cout << s << " is self-inventorying after "<<steps-1<<" steps"<<endl;
					break;
				}
				else if (int ret=check(steps)) {
					cout << s << " enters an inventory loop of length " << ret<<endl;
					break;
				}
				if (steps == 15) { 
					cout << s << " can not be classified after 15 iterations" << endl;
					break; 
				}
		}
	}
	fclose(stdin);
	fclose(stdout);
}