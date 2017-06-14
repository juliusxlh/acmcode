#include <stdio.h>
#include <iostream>
using namespace std;
int n,h,max_f,f[100][200],p[100][200],dc[100],fi[100],d[100];
int ppp()
{
	int i,j;
	for (i=1;i<=n;i++){
		for (j=1;j<=(dc[i]?fi[i]/dc[i]:h*12)+1;j++){
			p[i][j]=p[i][j-1]+fi[i]-(dc[i])*(j-1);
		}
	}
}
int main()
{
	int i,j,k;
	freopen("poj.in","r",stdin);
	freopen("poj.out","w",stdout);
	while (1){
	cin>>n;
	if (n==0) break;
	cin>>h;
	for (i=1;i<=n;i++) cin>>fi[i];
	for (i=1;i<=n;i++) cin>>dc[i];
	for (i=2;i<=n;i++) cin>>d[i];
	d[1]=0;
	ppp;
	max_f=0;
	for (i=1;i<=n;i++){
		for (j=0;j<=h*12;j++) {
			if (j-d[i]>=0) f[i][j]=f[i-1][j-d[i]];
		} 
		for (j=h*12;j>=0;j--){
			for (k=0;k<=(dc[i]?(fi[i]/dc[i]):h*12)+1;k++){
				if (f[i][j-k]+p[i][k]>f[i][j]) f[i][j]=f[i][j-k]+p[i][j];
			}
			if (f[i][j]>max_f) max_f=f[i][j];
		}
	} 
	cout<<max_f<<endl;
    }
	fclose(stdin);
	fclose(stdout);
}
