/*
徐立恒
zd_xlh@zju.edu.cn
WA:1wa
time:79ms
RANK:2245
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#define ff(a,b) for(int i=a;i!=b;i++)
using namespace std;
long long f[21][21],d[21][21],u[21][21];
bool flag[30];
int k,pre,ans[30],st,ed;

/*
预处理dp，
记忆化搜索
f[i][j]代表序列总共j个数，第一个为第i大的数的总数，
d[i][j]表示代表序列总共j个数，第一个为第i大的数，第二个数比i小的总数，
u[i][j]表示代表序列总共j个数，第一个为第i大的数，第二个数比i大的总数
f[i][j]=u[i1][j-1](i1=(1,i-1))+d[i2][j-1](i2=(i,j));
u[i][j]=d[i2][j-1](i2=(i,j));
d[i][j]=u[i1][j-1](i1=(1,i-1));
*/
void predp(int x,int y)
{
    if (f[x][y]) return;
    ff(1,y){
        predp(i,y-1);
        if (i<x){
            f[x][y]+=u[i][y-1];
            d[x][y]+=u[i][y-1];
        }else{
            f[x][y]+=d[i][y-1];
            u[x][y]+=d[i][y-1];
        }
    }
}

void output(int x,int y)
{
    int j=0;
    ff(1,k+1){
        if (flag[i]) j++;
        if (j==x){
            flag[i]=false;
            if (y!=k) cout<<' ';
            cout<<i;
            ans[k-y+1]=i;
            pre=x;
            return;
        }
    }
}

int main()
{
    freopen("poj.in","r",stdin);
    freopen("poj.out","w",stdout);
    int cs;
    cin>>cs;
    memset(f,0,sizeof(f));
    memset(u,0,sizeof(u));
    memset(d,0,sizeof(d));
    f[1][1]=1;
    d[1][1]=1;
    u[1][1]=1;
    ff(0,20) predp(i+1,20);
    while (cs--){
        int j;
        long long order;
        memset(flag,true,sizeof(flag));
        cin>>k>>order;
        j=k;
        while (j!=0){
            if (k-j<2){
                st=1;
                ed=j+1;
            }else{
                if (ans[k-j-1]>ans[k-j]){
                    st=pre;
                    ed=j+1;
                }else{
                    st=1;
                    ed=pre;
                }
            }
            ff(st,ed){
                if (j!=k){
                    if (i<pre){
                        if (order>u[i][j]) order-=u[i][j];else {output(i,j);break;};
                    }else{
                        if (order>d[i][j]) order-=d[i][j];else {output(i,j);break;};
                    }
                }else{
                    if (order>f[i][j]) order-=f[i][j]; else {output(i,j);break;};
                }
            }
            j--;
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}