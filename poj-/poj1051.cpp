#include <stdio.h>
#include <iostream>
#include <string>
#pragma warning(disable:4996)
using namespace std;
string Morse[30] = {
	"01",
	"1000",
	"1010",
	"100",
	"0",
	"0010",
	"110",
	"0000",
	"00",
	"0111",
	"101",
	"0100",
	"11",
	"10",
	"111",
	"0110",
	"1101",
	"010",
	"000",
	"1",
	"001",
	"0001",
	"011",
	"1001",
	"1011",
	"1100",
	"0011",
	"1110",
	"0101",
	"1111"
};
string mcode = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.,?";
int main()
{
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	int test;
	cin >> test;
	int Test=test;
	while (test != 0, test--) {
		string s, l = "",ans="";
		int f[1000];
		cin >> s;
		for (int i = 0; i != s.size(); i++) {
			l += Morse[mcode.find(s[i])];
			f[i] = Morse[mcode.find(s[i])].size();
		}
		for (int i = s.size() - 1; i >= 0; i--) {
			string r = l.substr(0,f[i]);
			for (int j = 0; j != 30; j++) {
				if (Morse[j] == r) {
					ans += char(mcode[j]);
					break;
				}
			}
			l.erase(0, f[i]);
		}
		cout << Test-test << ": " << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
}