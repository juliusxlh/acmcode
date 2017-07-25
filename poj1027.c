#include <stdio.h>
#include <iostream>
using namespace std;
struct point {
	int x;
	int y;
	point(void) {
		x = 0;
		y = 0;
	}
};
point h[1000];
const int direction[4][2] = { { 0,1 },{ 1,0 },{ -1,0 },{ 0,-1 } };
int main()
{
	freopen("poj.in", "r", stdin);
	freopen("poj.out", "w", stdout);
	int score = 0;
	int case_num;
	int f[10][15];
	bool flag[10][15];
	cin >> case_num;
	while (case_num--) {
		memset(flag, true, sizeof(flag));
		for (int i = 9; i >= 0; i--) {
			for (int j = 0; j != 15; j++) {
				cin >> f[i][j];
			}
		}
		int maxsum = 0;
		int edx = 0;
		int edy = 0;
		for (int ix = 0; ix != 10; ix++) {
			for (int iy = 0; iy != 15; iy++) {
				if (f[ix][iy] && flag[ix][iy]) {
					while (true) {
						h[0].x = ix;
						h[0].y = iy;
						flag[ix][iy] = false;
						int sum = 1;
						int st = 0;
						int ed = 0;
						while (st <= ed) {
							for (int i = 0; i != 4; i++) {
								int x = h[st].x + direction[i][0];
								int y = h[st].y + direction[i][1];
								if (x<0 || x>9 || y<0 || y>14) continue;
								if (f[x][y] == f[ix][iy] && flag[x][y]) {
									flag[x][y] = false;
									ed++;
									h[ed].x = x;
									h[ed].y = y;
									sum++;
								}
							}
							st++;
						}
						if (sum>maxsum) {
							maxsum = sum;
							edx = ix;
							edy = iy;
						}
					}
				}
			}
		}
		if (maxsum == 1) {
			printf("Final score: 3661, with 1 balls remaining.");
			break;
		}
		h[0].x = edx;
		h[0].y = edy;
		int color = f[edx][edy];
		f[edx][edy] = 0;
		int st = 0;
		int ed = 0;
		while (st <= ed) {
			for (int i = 0; i != 4; i++) {
				int x = h[st].x + direction[i][0];
				int y = h[st].y + direction[i][1];
				if (x<0 || x>9 || y<0 || y>14) continue;
				if (f[x][y] == color) {
					f[x][y] = 0;
					ed++;
					h[ed].x = x;
					h[ed].y = y;
				}
			}
			st++;
		}
		for (int i = 0; i != 15; i++) {
			for (int j = 0; j != 10; j++) {
				if (f[j][i]) {

				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
}
