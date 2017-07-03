#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
#pragma warning (disable:4996)
int f[10];
int main()
{
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	while (cin>>f[1]>>f[2]>>f[3]>>f[4]>>f[5]>>f[6],!(f[1]==0&&f[2]==0&&f[3]==0&&f[4]==0&&f[5]==0&&f[6]==0)) {
		int sum = 0;
		sum = sum + f[6] + f[5];
		if (11 * f[5] >= f[1]) f[1] = 0; else f[1] -= 11 * f[5];
		sum = sum + f[4];
		if (5 * f[4] >= f[2]) { 
			if (f[1] > (5 * f[4] - f[2]) * 4) {
				f[1] -= (5 * f[4] - f[2]) * 4;
			}
			else f[1] = 0;
			f[2] = 0; 
		}
		else f[2] -= 5 * f[4];
		sum += f[3] / 4;
		f[3] = f[3] % 4;
		sum += f[2] / 9;
		f[2] = f[2] % 9;
		if (f[3] == 3 && f[2] <= 1) {
			sum+=1;
			int left = 36 - 9 * f[3] - 4 * f[2];
			if (f[1] > left) sum += ceil((f[1]-left)/36.0);
		}
		else if (f[3]==3){
			sum += 2;
			int left = 72 - 9 * f[3] - 4 * f[2];
			if (f[1] > left) sum += ceil((f[1] - left) / 36.0);
		}
		if (f[3] == 2 && f[2] <= 3) {
			sum += 1;
			int left = 36 - 9 * f[3] - 4 * f[2];
			if (f[1] > left) sum += ceil((f[1] - left) / 36.0);
		}
		else if (f[3] == 2) {
			sum += 2;
			int left = 72 - 9 * f[3] - 4 * f[2];
			if (f[1] > left) sum += ceil((f[1] - left) / 36.0);
		}
		if (f[3] == 1 && f[2] <= 5) {
			sum += 1;
			int left = 36 - 9 * f[3] - 4 * f[2];
			if (f[1] > left) sum += ceil((f[1] - left) / 36.0);
		}
		else if (f[3] == 1) {
			sum += 2;
			int left = 72 - 9 * f[3] - 4 * f[2];
			if (f[1] > left) sum += ceil((f[1] - left) / 36.0);
		}
		if (f[3] == 0&&(f[2]!=0||f[1]!=0)) {
			sum += 1;
			int left = 36 - 9 * f[3] - 4 * f[2];
			if (f[1] > left) sum += ceil((f[1] - left) / 36.0);
		}
		cout << sum << endl;
	}
	fclose(stdin);
	fclose(stdout);
}