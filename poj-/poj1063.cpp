#include <stdio.h>
#include <iostream>
#pragma warning (disable:4996)
using namespace std;
int main()
{
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	int cases;
	cin >> cases;
	while (cases) {
		--cases;
		int n;
		int sum = 0;
		int black = 0;
		cin >> n;
		for (int i = 0; i != n; i++) {
			int a;
			cin >> a;
			if (a == 1 && i % 2 == 0) ++sum;
			if (a == 1) black++;
		}
		if (n % 2 == 1) cout << "YES"<<endl; else {
			if (black%2==1&&(sum==black/2||sum==black/2+1)) cout << "YES" << endl;else 
				if (black % 2 == 0 && (sum == black / 2)) cout << "YES" << endl; else
					cout << "NO" << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
}