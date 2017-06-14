#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
const int fin = 405;
#pragma warning(disable:4996)
using namespace std;
int f[500][500];
map<string, int>name_map;
int main()
{
	int n, sum = 0, m, sum_flow = 0, st, ed, h[1000], pre[500];
	bool bl[500];
	string s1,s2;
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s1;
		if (name_map.find(s1) == name_map.end()) {
			sum++;
			name_map[s1] = sum;
			f[0][sum] += 1;
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> s1 >> s2;
		if (name_map.find(s1) == name_map.end()) {
			sum++;
			name_map[s1] = sum;
		}
		if (name_map.find(s2) == name_map.end()) {
			sum++;
			name_map[s2] = sum;
		}
		f[name_map[s2]][name_map[s1]] += 1;
		f[name_map[s1]][fin] += 1;
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> s1 >> s2;
		if (name_map.find(s1) == name_map.end()) {
			sum++;
			name_map[s1] = sum;
		}
		if (name_map.find(s2) == name_map.end()) {
			sum++;
			name_map[s2] = sum;
		}
		f[name_map[s2]][name_map[s1]] = 100000;
	}
	while (true) {
		st = 0;
		ed = 0;
		int maxf = 100000;
		memset(bl, true, 500 * sizeof(bool));
		memset(h, 0, 1000 * sizeof(int));
		bl[0] = false;
		bool flag=false;
		while (st <= ed) {
			int i;
			for (i=1;i<=fin;i++)
				if (f[h[st]][i]>0&&bl[i]) {
					ed++;
					bl[i] = false;
					pre[i] = h[st];
					h[ed] = i;
					if (i == fin) { flag = true; break; }
				}
			if (flag) break;
			st++;
		}
		if (flag == false) break;
		int b4 = fin;
		while (b4 != 0) {
			if (f[pre[b4]][b4]<maxf)  maxf=f[pre[b4]][b4];
			b4 = pre[b4];
		}
		b4 = fin;
		while (b4!=0) {
			f[pre[b4]][b4] -= maxf;
			f[b4][pre[b4]] += maxf;
			b4 = pre[b4];
		}
		sum_flow+=maxf;
	}
	cout << m - sum_flow;
	fclose(stdin);
	fclose(stdout);
}