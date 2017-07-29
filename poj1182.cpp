#include <iostream>
#include <stdio.h>
#define ff(a,b) for (int i=a;i!=b;i++)
struct point{
    int fat;
    int dis;
};
using namespace std;
int n,k;
point f[50005];

point findfather(int x)
{
    point a;
    if (f[x].fat==x) return f[x];
    a=findfather(f[x].fat);
    f[x].fat=a.fat;
    f[x].dis+=a.dis;
    return f[x];
}
int p(int x)
{
    if (x<0){
        return x%3+3;
    }
    return x%3;
}
int main()
{
    freopen("poj.in","r",stdin);
    freopen("poj.out","w",stdout);
    cin>>n>>k;
    ff(1,n+1) {
        f[i].fat=i;
        f[i].dis=0;
    }
    int fal=0;
    ff(0,k){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if (b>n||c>n){
            fal++;
            continue;
        }
        point fa,fb;
        fa=findfather(b);
        fb=findfather(c);
        if (fa.fat!=fb.fat){
            f[fa.fat].fat=fb.fat;
            if (a==1)f[fa.fat].dis=p(f[c].dis-f[b].dis);else f[fa.fat].dis=p(f[c].dis-f[b].dis+1);
        }else{
            if (a==1&&p(f[b].dis)!=p(f[c].dis)) fal++;else
            if (a==2&&p(f[b].dis-f[c].dis)!=1) fal++;
        }
    }
    cout<<fal<<endl;
    fclose(stdin);
    fclose(stdout);
}