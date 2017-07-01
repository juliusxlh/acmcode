#include <stdio.h>  
#include <iostream>
#include <string>
#pragma warning (disable:4996)
using namespace std;
string s;
bool flag;
struct Tree {
	Tree* left;
	Tree* right;
	int x;
	Tree() {
		left = NULL;
		right = NULL;
		x = 1;
	}
};
Tree *head;
Tree* ins(int x,Tree* head)
{
	if (x == s.size()) {
		if (head == NULL) {
			head = new Tree;
			head->x = 2;
			return head;
		}
		else {
			flag = false;
			return head;
		}
	}
	if (head == NULL) head = new Tree;
	if (head->x == 2) {
		flag = false;
		return head;
	}
	if (s[x] == '0') head->left = ins(x + 1, head->left);
	if (s[x] == '1') head->right = ins(x + 1, head->right);
	return head;
}
int main()
{
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	int cases=0;
	while (cin >> s) {
		cases++;
		head = new Tree;
		flag = true;
		if (s == "9") {
			cout << "Set " << cases << " is immediately decodable" << endl;
			continue;
		}
		head = ins(0, head);
		while (cin >> s, s != "9") {
			if (flag) head = ins(0, head);
		}
		if (flag) cout << "Set " << cases << " is immediately decodable"<<endl; else
			cout << "Set " << cases << " is not immediately decodable"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}