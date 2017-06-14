#include <stdio.h>
#include <iostream>
#include <vector>
#pragma warning	(disable:4996)
using namespace std;
vector<int> Joseph;
int ans[20] = { 0,2
,7,
5,
30,
169,
441,
1872,
7632,
1740,
93313,
459901,
1358657,
2504881 };
void main()
{
	/*freopen("poj.out", "w", stdout);
	for (int i = 1; i != 14; i++) {
		int minj = 0;
		while (true){
			minj++;
			int st = 0;
			for (int j = 0; j < i * 2; j++) Joseph.push_back(j);
			bool flag = true;
			while (Joseph.size()!=i) {
				if (Joseph[(st + minj - 1) % Joseph.size()] < i) {
					flag = false;
					break;
				}
				else {
					Joseph.erase(Joseph.begin()+(st + minj - 1) % Joseph.size());
				    st = (st + minj - 1)%(Joseph.size()+1);
					if (st == Joseph.size()) st = 0;
				}
			}
			Joseph.clear();
			if (flag == true) {
				ans[i] = minj;
				cout << minj << endl;
				break;
			}
		}
	}
	fclose(stdout);*/
	int n;
	while (cin >> n, n != 0) {
		cout << ans[n] << endl;
	}
}