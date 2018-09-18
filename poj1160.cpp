#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

#define MAX_DIS 3000000
#pragma warning (disable:4996)
using namespace std;

/*
	动态规划 f[i][j][k] = max(f[i-1][j][k] + dis[i] - dis[k], f[i-1][j-1][x = 1..k] + dis_s[x,k])
	dis_t[x,k] 为第x与第k村庄有邮局，那之间的村庄离邮局的最近距离和
*/

class PostOffice
{
public:
	void slove()
	{
		input();
		preprocess();
		dp();
	}

	void dp()
	{
		memset(f, 0, sizeof(int) * 2 * 31 * 300);
		for (int i = 1; i != Vnum; i++) {
			int nowi = i % 2;
			int prei = (i - 1) % 2;
			for (int j = 0; j <= POnum; j++) {
				for (int k = 0; k != Vnum; k++) {
					f[nowi][j][k] = 0;
				}
			}
			for (int j = 1; j <= POnum; j++) {
				for (int k = 0; k <= i; k++) {
					if (k == i) {
						int min = MAX_DIS;
						if (j != 1) {
							for (int l = 0; l != k; l++) {
								if (f[prei][j - 1][l] + dis_t[l][k] - dis_l[l][i-1]< min) min = f[prei][j - 1][l] + dis_t[l][k]- dis_l[l][i-1];
							}
						}
						else {
							min = f[prei][j - 1][0] + dis_t[k][k];
						}
						f[nowi][j][k] = min;
					}
					else f[nowi][j][k] = f[prei][j][k] + abs(dis[i]-dis[k]);
				}
			}
		}
		int min = MAX_DIS;
		for (int i = 1; i != Vnum; i++) {
			if (f[(Vnum - 1) % 2][POnum][i] < min) min = f[(Vnum - 1) % 2][POnum][i];
		}
		printf("%d\n", min);
	}

	void preprocess()
	{
		sort(dis, dis + Vnum);
		for (int i = 0; i != Vnum; i++) {
			for (int j = i; j != Vnum; j++) {
				int sum = 0;
                int sum_l = 0;
                if (i != j) {
					for (int k = i; k != j; k++) {
						if (abs(dis[i] - dis[k]) < abs(dis[j] - dis[k])) sum += abs(dis[i] - dis[k]);
						else sum += abs(dis[j] - dis[k]);
                        sum_l += abs(dis[i] - dis[k + 1]);
                    }
				}
				else {
					for (int k = 0; k != j; k++) {
						sum += abs(dis[j]-dis[k]);
					}
				}
				dis_t[i][j] = sum;
                dis_l[i][j] = sum_l;
            }
		}
	}

	void input()
	{
		cin >> Vnum >> POnum;
		for (int i = 0; i != Vnum; i++) cin >> dis[i];

	}
private:
	int dis_t[300][300];
    int dis_l[300][300];
    int dis[300];// the poistion of villiages
	int f[2][31][300];
	int POnum;// the number of post office
	int Vnum;// the number of villiages
};

int main()
{
	freopen("poj.in","r",stdin);
	freopen("poj.out","w",stdout);
	PostOffice post_office;
	post_office.slove();
	fclose(stdin);
	fclose(stdout);
}