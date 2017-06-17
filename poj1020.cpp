#include <stdio.h>
#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
bool bl[20];
int n,f[20],h[100],Size;
bool cop(int a, int b)
{
	return a > b;
}
bool check(int x, int y, int z)
{
	for (int i = x; i != x + z; i++) {
		if (y < h[i]) return false;
	}
	return true;
}
bool dfs(int deep)
{
	int x = 0, y = 0;
	for (int i = 0; i != Size; i++)
		if (h[i] < h[x]) x = i;
	y = h[x];
	if (deep == n) return true;
	bool flags = true;
	for (int i = 10; i != 0; i--) {
		if (f[i] && flags) {
			flags = false;
			int max = 0;
			int now = 0;
			for (int j = 0; j != Size; j++) {
				if (Size - h[j] >= i) now++; else now = 0;
				if (now > max) max = now;
			}
			if (max < i) return false;
		}
		if (f[i]&&x+i<=Size&&y+i<=Size&&check(x,y,i)) {
			for (int j = x; j != x + i; j++) h[j] += i;
			f[i]--;
			if (dfs(deep+1)) return true;
			f[i]++;
			for (int j = x; j != x + i; j++) h[j] -= i;
		}
	}
	return false;
}
int main()
{
	freopen("poj.in","r",stdin);
	freopen("poj.out", "w", stdout);
	int caseT;
	cin >> caseT;
	for (int i = 0; i != caseT; i++) {
		memset(h, 0, 100 * sizeof(int));
		memset(f, 0, 20 * sizeof(int));
		cin >> Size;
		cin >> n;
		int sum = 0;
		for (int j = 0; j != n; j++) {
			int a;
			cin >> a;
			f[a]++;
			sum += a * a;
		}
		if (sum != Size*Size) {
			cout << "HUTUTU!" << endl;
			continue;
		}
		if (dfs(0)) cout << "KHOOOOB!"<<endl; else cout << "HUTUTU!"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}