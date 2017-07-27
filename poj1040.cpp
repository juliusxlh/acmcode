#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#define ff(a,b) for (int i=a;i!=b;i++)
#define in(a,b,c) cin>>a>>b>>c
using namespace std;
struct orders{
    int start;
    int end;
    int num;
};

orders f[30];
int ans[30],sum[30];
int n,station,order,mas;

inline bool cop(orders x,orders y)
{
    return (x.end-x.start)*x.num>(y.end-y.start)*y.num;
}
void dfs(int now,int deep)
{
    if (deep==order){
        if (now>mas) mas=now;
        if (now==9204){
            ans[deep]=0;
        }
        return;
    }
    if (now+sum[deep]<=mas) return;
    bool flag=true;
    ff(f[deep].start+1,f[deep].end+1){
        ans[i]+=f[deep].num;
        if (ans[i]>n) flag=false;
    }
    if (flag) dfs(now+f[deep].num*(f[deep].end-f[deep].start),deep+1);
    ff(f[deep].start+1,f[deep].end+1){
        ans[i]-=f[deep].num;
    }
    dfs(now,deep+1);
}

int main()
{
    freopen("poj.in","r",stdin);
    freopen("poj.out","w",stdout);
    while (in(n,station,order),n!=0||station!=0||order!=0){
        ff(0,order){
            in(f[i].start,f[i].end,f[i].num);
        }
        sort(f,f+order,cop);
        memset(sum,0,sizeof(sum));
        sum[order-1]=f[order-1].num*(f[order-1].end-f[order-1].start);
        for (int i=order-2;i>=0;i--){
            sum[i]=sum[i+1]+f[i].num*(f[i].end-f[i].start);
        }
        mas=0;
        memset(ans,0,sizeof(ans));
        dfs(0,0);
        cout<<mas<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}