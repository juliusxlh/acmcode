#include <stdio.h>
#include <string>
#include <iostream>
#pragma warning (disable:4996)
using namespace std;
string s1[3], s2[3], s3[3];
void input()
{
	for (int i = 0; i < 3; i++) {
		cin >> s1[i] >> s2[i] >> s3[i];
	}
}
bool check(string s, char x)
{
	for (int i = 0; i != s.size(); i++) {
		if (x == s[i]) return true;
	}
	return false;
}
int main()
{
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	int casen;
	cin >> casen;
	while (casen) {
		casen--;
		input();
		for (int i = 0; i < 12; i++) {
			bool flag = true;
			string status = "";
			for (int j = 0; j < 3; j++) {
				if (check(s1[j],i+'A')) {
					if (s3[j] == "even") {
						flag = false;
						break;
					}
					else if (status == "") {
						if (s3[j] == "up") status = "heavy"; else status = "light";
					} else
						if (!((status=="heavy"&&s3[j]=="up")||(status=="light"&&s3[j]=="down"))) {
							flag = false;
							break;
						}
				}else
					if (check(s2[j], i + 'A')) {
						if (s3[j] == "even") {
							flag = false;
							break;
						}
						else if (status == "") {
							if (s3[j] == "down") status = "heavy"; else status = "light";
						}
						else
							if (!((status == "heavy"&&s3[j] == "down") || (status == "light"&&s3[j] == "up"))) {
								flag = false;
								break;
							}
					}else if (s3[j] != "even") {
						flag = false;
						break;
				}
			}
			if (flag&&status!="") {
				cout << (char)(i + 'A') << " is the counterfeit coin and it is " << status << '.'<<endl;
				break; 
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
}
