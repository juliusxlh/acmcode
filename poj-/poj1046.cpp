#include <stdio.h>
#include <iostream>
#include <cmath>
#pragma warning (disable:4996)
using namespace std;
int main()
{
	int f[16][3];
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	for (int i = 0; i < 16; i++) {
		cin >> f[i][0] >> f[i][1] >> f[i][2];
	}
	int a, b, c;
	while (cin >> a >> b >> c, a != -1 || b != -1 || c != -1) {
		double min = 100000000; 
		int mini = -1;
		for (int i = 0; i < 16; i++) {
			double dis = pow(double(f[i][0]-a),2)+ pow(double(f[i][1] - b),2)+ pow(double(f[i][2] - c),2);
			if (dis < min) {
				min = dis;
				mini = i;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",a,b,c,f[mini][0],f[mini][1],f[mini][2]);
	}
	fclose(stdin);
	fclose(stdout);
}