#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    freopen("poj.in","r",stdin);
    freopen("poj.out","w",stdout);
    int n, m;
    int a[101][101];
    int f[101][101];
    memset(f, 0 ,sizeof(int)*101*101);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m;j++){
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= m;j++){
            if (f[i][j-1] > f[i-1][j-1]+a[i][j] && j>i)
                f[i][j] = f[i][j - 1];
            else
                f[i][j] = f[i - 1][j - 1] + a[i][j];
        }
    }
    printf("%d\n", f[n][m]);
    fclose(stdin);
    fclose(stdout);
}