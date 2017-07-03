#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#define maxi 32000
#pragma warning(disable:4996)
int lengthint[maxi],l[maxi];
long long suml[maxi];
using namespace std;
void pretreatment() {
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	for (int i = 1; i < maxi; i++) {
		if (i < 10) l[i] = 1; else
			if (i < 100)l[i] = 2; else
				if (i < 1000) l[i] = 3; else
					if (i < 10000) l[i] = 4; else l[i] = 5;
		lengthint[i] = lengthint[i - 1] + l[i];
	}
	for (int i = 1; i < maxi; i++) suml[i] = suml[i - 1] + lengthint[i];
}
void cal()
{
	stringstream ss;
	int casenum,n;
	cin >> casenum;
	for (int i = 0; i < casenum; i++) {
		cin >> n;
		for (int j = 1; j < maxi; j++) {
			if (n > lengthint[j]) n -= lengthint[j]; else {
				for (int k = 1; k <= j; k++) {
					if (n > l[k]) n -= l[k]; else {
						string s;
						ss << k;
						ss >> s;
						cout << s[n-1]<<endl;
						ss.clear();
						break;
					}
				}
				break;
			}
		}
	}
}
int main()
{
	pretreatment();
	cal();
	fclose(stdin);
	fclose(stdout);
}