#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int f[110][110];
int main()
{
    freopen("poj.in","r",stdin);
    freopen("poj.out","w",stdout);
    int n,k;
    while (cin>>n,n!=0){
        for (int i=0;i!=n;i++){
            for (int j=0;j!=n;j++) if (i!=j) f[i][j]=100000;else f[i][j]=0;
        }
        for (int i=0;i!=n;i++){
            cin>>k;
            for (int j=0;j!=k;j++){
                int a,b;
                cin>>a>>b;
                f[i][a-1]=b;
            }
        }
        for (int k=0;k!=n;k++){
            for (int i=0;i!=n;i++){
                for (int j=0;j!=n;j++){
                    if (f[i][k]+f[k][j]<f[i][j]) f[i][j]=f[i][k]+f[k][j];
                }
            }
        }
        int mas=100000;
        int masi=-1;
        for (int i=0;i!=n;i++){
            bool flag=true;
            int b=0;
            for (int j=0;j!=n;j++){
                if (f[i][j]==INT_MAX){
                    flag=false;
                    break;
                }
                if (f[i][j]>b) b=f[i][j];
            }
            if (flag){
                if (b<mas) {
                    mas=b;
                    masi=i;
                }
            }
        }
        if (masi==-1) cout<<"disjoint"<<endl;else cout<<masi+1<<' '<<mas<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}