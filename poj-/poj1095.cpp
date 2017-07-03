#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#define maxn 20
#pragma warning (disable:4996)
using namespace std;
struct Tree {
	Tree* left;
	Tree* right;
	Tree() {
		left = NULL;
		right = NULL;
	}
};
Tree* head = new Tree;
int n;
string answer = "";
int NumberOfNTree[maxn];
void pre()
{
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	NumberOfNTree[0] = 1;
	NumberOfNTree[1] = 1;
	for (int i = 2; i != maxn; i++) {
		NumberOfNTree[i] = 0;
		for (int j = 0; j != i; j++){
			NumberOfNTree[i] += (NumberOfNTree[j]*NumberOfNTree[i-1-j]);
		}
	}
}
void endpro()
{
	fclose(stdin);
	fclose(stdout);
}
Tree* build(Tree*head,int x,int y)
{
	if (x == 0) return NULL;
	if (head == NULL) head = new Tree;
	if (x == 1) return head;
	for (int i = 0; i != x; i++) {
		if (NumberOfNTree[i]*NumberOfNTree[x-i-1]>=y) {
			head->left = build(head->left, i, (y-1)/ NumberOfNTree[x-i-1] + 1);
			head->right = build(head->right, x-i-1, (y-1) % NumberOfNTree[x-i-1] + 1);
			break;
		}
		else y -= NumberOfNTree[i] * NumberOfNTree[x - i - 1];
	}
	return head;
}
string draw(Tree* head)
{
	if (head == NULL) return "";
	string ret = "X";
	string lret = draw(head->left);
	string rret = draw(head->right);
	if (lret != "") ret = "(" + lret + ")"+ret;
	if (rret != "") ret = ret + "(" + rret + ")";
	return ret;
}
void deal()
{
	head = new Tree;
	int i = 1;
	while (n > NumberOfNTree[i]) {
		n -= NumberOfNTree[i];
		i++;
	}
	head=build(head,i,n);
	answer=draw(head);
	cout << answer << endl;
}
int main()
{
	pre();
	while (cin >> n, n != 0) {
		deal();
	}
	endpro();
}