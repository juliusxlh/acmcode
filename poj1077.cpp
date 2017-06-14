#include <stdio.h>
#include <iostream>
#include <string>
#define MAXI 410000
#pragma warning(disable:4996)
using namespace std;
struct eight {
	int pre;
	char c;
};
eight pre[MAXI];
bool bl,visit[MAXI];
int l[10],r[10],s, h[MAXI],p[MAXI];
string ans;
int STtoINT(int x)
{
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		sum += (x / l[i] % 10) * r[i];
	}
	return sum;
}
void change(int x, int y, int* ed, int st, char o)
{
	int a, b, c;
	*ed = *ed + 1;
	a = h[st] / l[x] % 10;
	b = h[st] / l[y] % 10;
	h[*ed] = h[st] - a*(l[x] - l[y]) - b*(l[y] - l[x]);
	c = STtoINT(h[*ed]);
	if (visit[c]==false){
		(*ed)--;
		return;
	}else visit[c] = false;
	if (h[*ed] == 987654321) bl = true;
	pre[*ed].pre = st;
	pre[*ed].c = o;
	p[*ed] = y;
}
void search(int x)
{
	if (x == 0) return;
	ans = pre[x].c+ans;
	search(pre[x].pre);
}

int main()
{
	int st, ed, i;
	char c;
	memset(visit, true, MAXI * sizeof(bool));
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	string str;
	l[0] = 1;
	bl = false;
	s = 0;
	r[0] = 1;
	for (i = 1; i < 9; i++) r[i] = r[i - 1] * (i);
	r[0] = 0;
	for (i = 0; i<9; i++) {
		cin >> c;
		if (c != 'x') s = s + (c - '0')*l[i]; else {
			s += 9 * l[i]; 
			p[0] = i;
		}
		l[i + 1] = l[i] * 10;
	}
	st = 0;
	ed = 0;
	h[0] = s;
	visit[STtoINT(s)] = false;
	while (st <= ed) {
		if (p[st]>2) change(p[st], p[st] - 3, &ed, st, 'u');
		if (bl) goto end;
		if (p[st]<6) change( p[st], p[st] + 3, &ed, st, 'd');
		if (bl) goto end;
		if (p[st] % 3 != 0) change(p[st], p[st] - 1, &ed, st, 'l');
		if (bl) goto end;
		if (p[st] % 3 != 2) change(p[st], p[st] + 1, &ed, st, 'r');
		if (bl) goto end;
		st++;
	}
	if (!bl) goto close;
end:
	search(ed);
	cout << ans;
close:
	if (!bl) cout << "unsolvable";
	fclose(stdin);
	fclose(stdout);
}