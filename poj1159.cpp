#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char s[5005];
short f[5005][5005];
int main()
{
    freopen("poj.in","r",stdin);
    freopen("poj.out","w",stdout);
    int n;
    cin>>n;
    cin>>s;
    for (int i=1;i<n;i++){
        for (int j=0;j+i<n;j++){
            if (s[i+j]==s[j]) f[j][i+j]=f[j+1][i+j-1];else {
                int now=f[j+1][i+j]+1;
                if (f[j][i+j-1]+1<now) now=f[j][i+j-1]+1;
                if (f[j+1][i+j-1]+2<now) now=f[j+1][i+j-1]+2;
                f[j][i+j]=now;
            }
        }
    }
    if (n!=0) cout<<f[0][n-1];else cout<<0;
    fclose(stdin);
    fclose(stdout);
}