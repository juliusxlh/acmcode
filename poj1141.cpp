#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#define MAX_BAR 1000
using namespace std;

#define MAXN 256
char br[MAXN];
int a[1001];
int f[201][201];
bool p[201][201];
string q[201][201];
void dfs(int x,int y)
{
    if (p[x][y])
        return;
    if (x==y) {
        f[x][y] = 1;
        p[x][y] = 1;
        if (a[x]==-1||a[x]==1)
            q[x][y] = "()";
        else
            q[x][y] = "[]";
        return;
    }
    if (y-x==1){
        if (a[x]+a[y]==0 && a[x]<0){
            f[x][y] = 0;
            if (a[x]==-1||a[x]==1)
                q[x][y] = "()";
            else
                q[x][y] = "[]";
        }
        else{
            if (a[x]==-1||a[x]==1)
                q[x][y] = "()";
            else
                q[x][y] = "[]";
            if (a[y]==-1||a[y]==1)
                q[x][y] += "()";
            else
                q[x][y] += "[]";
            f[x][y] = 2;
        }
        p[x][y] = 1;
        return;
    }
    int min = MAX_BAR;
    int pos = x;
    if (a[x]+a[y] == 0 && a[x]<0) {
        dfs(x + 1, y - 1);
        int ret = f[x + 1][y - 1];
        if (ret<min){
            min = ret;
            pos = -1;
        }
    }
    for (int i = x; i != y;i++){
        dfs(x, i);
        dfs(i + 1, y);
        int ret = f[x][i] + f[i + 1][y];
        if (ret<min){
            min = ret;
            pos = i;
        }
    }
    f[x][y] = min;
    p[x][y] = 1;
    if (pos == -1){
        if (a[x]==-1||a[x]==1) {
            q[x][y] += '(';
            q[x][y] += q[x + 1][y - 1];
            q[x][y] += ')';
        } else{
            q[x][y] += '[';
            q[x][y] += q[x + 1][y - 1];
            q[x][y] += ']';           
        }
    } else
        q[x][y] = q[x][pos] + q[pos + 1][y];
    return ;
}

int main()
{
    freopen("poj.in","r",stdin);
    freopen("poj.out","w",stdout);
    while (gets(br) != NULL) {
    int n = 0;
    char ch;
    memset(f,0,sizeof(int)*201*201);
    memset(p,0,sizeof(bool)*201*201);
    int i = 0;
    while (br[i]!='\0'){
        ch = br[i];
        if (ch=='(')
            a[n] = -1;
        else if (ch == ')')
            a[n] = 1;
            else if (ch == '[')
                a[n] = -2;
                else if (ch==']')
                    a[n] = 2;
        if (ch=='(' || ch == ')' || ch == '[' || ch == ']') n++;
        i++;
    }
    if (n==0) {
        cout << "\n";
    } else{
    dfs(0, n-1);
    cout << q[0][n-1] << endl;
    for (int i = 0; i != n;i++)
    {
        for (int j = 0; j != n;j++)
            q[i][j].clear();
    }
    }
    }
    fclose(stdin);
    fclose(stdout);
}