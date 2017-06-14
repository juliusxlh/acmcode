#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
struct St {
	int x;
	int y;
};
St Stamps[200];
int Customers;
int MaxValue=0;
int TotalTypes = 0;
int StampNum = 0;
vector<St> Answer,Ans;
bool flag;
bool cop(St a,St b)
{
	return a.x < b.x;
}
bool com(St a, St b)
{
	return a.y < b.y;
}
void dfs(int x,int y,int z,int u,int v)
{
	if (y == 0) {
		if (TotalTypes == v&&StampNum == z&&MaxValue == Stamps[u].x) {
			flag = true;
		}
		if (TotalTypes < v || (TotalTypes == v && (StampNum > z || (StampNum == z&& MaxValue < Stamps[u].x)))) {
			MaxValue = Stamps[u].x;
			StampNum = z;
			TotalTypes = v;
			Ans = Answer;
			flag = false;
		}
		return;
	}
	if (z == 4) return;
	if (4 - z + v < TotalTypes) return;
	if (4 - z + v == TotalTypes&&z > StampNum) return;
	for (int i = (z==0?x:x-1); i >= 0; i--) {
		if (y - Stamps[i].x >= 0 && Stamps[i].x != 0) {
			if (y > Stamps[i].x * (4 - z)) break;
			Answer.push_back(Stamps[i]);
			dfs(i, y - Stamps[i].x, z + 1, z == 0 ? i : u, v + 1);
			Answer.pop_back();
		}
	}
	if (z!=0&&(y - Stamps[x].x >= 0 && Stamps[x].x != 0&& (y <= Stamps[x].x * (4 - z)))) {
		Answer.push_back(Stamps[x]);
		dfs(x, y - Stamps[x].x, z + 1, z==0?x:u,z==0?v+1:v);
		Answer.pop_back();
	}
}
int main()
{
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	while (cin>>Stamps[0].x) {
		int sum = 1;
		Stamps[0].y = 0;
		while (cin >> Stamps[sum].x, Stamps[sum].x != 0) { Stamps[sum].y = sum;sum++; }
		sort(Stamps,Stamps+sum,cop);
		while (cin >> Customers, Customers != 0) {
			MaxValue = 0;
			StampNum = 0;
			TotalTypes = 0;
			dfs(sum-1,Customers,0,0,0);
			if (MaxValue == 0 && StampNum == 0 && TotalTypes == 0) cout << Customers << " ---- none" << endl; else {
				if (flag) cout << Customers << " (" << TotalTypes << "): tie" << endl; else {
					cout << Customers << " (" << TotalTypes << "):";
					sort(Ans.begin(), Ans.end(), com);
					for (int i = 0; i < Ans.size(); i++) cout << ' ' << Ans[i].x;
					cout << endl;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
}