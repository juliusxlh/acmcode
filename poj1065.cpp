#include <stdio.h>
#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
bool flag,flags;
int Size;
struct wooden {
	int x;
	int y;
};
struct tree {
	tree *left, *right;
	int x;
};
tree* head;
bool cop(wooden a, wooden b)
{
	if (a.x > b.x) return true;
	if (a.x == b.x&&a.y > b.y) return true;
	return false;
}
tree* del(int x,tree* y)
{
	if (y->right != NULL) {
		tree* p = y->right;
		tree* pre = y;
		while (p->left!=NULL) {
			p = p->left;
			if (pre != y) pre = pre->left; else pre = pre->right;
		}
		y->x = p->x;
		if (pre != y) pre->left = p->right; else pre->right = p->right;
		return y;
	}
	else {
		y = y->left;
		return y;
	}
}
tree* ins(int x,tree* y)
{
	if (y == NULL) {
		y = new tree;
		y->x = x;
		y->left = NULL;
		y->right = NULL;
		return y;
	}
	if (x > y->x) {
		y->right = ins(x, y->right);
		return y;
	}
	else {
		y->left = ins(x, y->left);
		return y;
	}
}
tree* dfs(int x,tree *y)
{
	if (flag) return y;
	if (y == NULL) {
		if (flags) return y;
		flag = true;
		Size++;
		return y;
	}
	if (y->x >= x) {
		flags = true;
		y->left=dfs(x, y->left);
		if (flag) return y;  else {
			y=del(x,y);
			flag = true;
			return y;
		}
	}
	else {
		y->right=dfs(x, y->right);
		if (flag) return y;
	}
	return y;
}
int main()
{
	int caseT;
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	cin >> caseT;
	for (int i = 0; i != caseT; i++) {
		int n;
		wooden f[5050];
		cin >> n;
		for (int j = 0; j != n; j++) cin >> f[j].x >> f[j].y;
		sort(f, f + n, cop);
		Size = 1;
		head = new tree;
		head->x = f[0].y;
		head->left = NULL;
		head->right = NULL;
		for (int j = 1; j != n; j++) {
			flag = false;
			flags = false;
			head=dfs(f[j].y, head);
			head = ins(f[j].y, head);
		}
		cout << Size << endl;
	}
	fclose(stdin);
	fclose(stdout);
}