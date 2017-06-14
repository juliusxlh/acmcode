#include <stdio.h>
#include <iostream>
#include <climits>
#include <string>
#include <math.h>
using namespace std;
int mini,min_[10005];
int dfs(int nleft,int deep,int lasthi,int lastri,int cost)
{
	int now,i,j; 
	if (nleft==0&&deep==0){
		mini=cost;
		return 0;
	}
	if (deep==0) return 0;
	if (nleft<=0) return 0;
	for (i=lastri-1;i>0;i--){
		if (nleft/(i*i)<lasthi-1) now=nleft/(i*i);else now=lasthi-1;
		for (j=now;j>0;j--){
			if (cost+2*nleft/i<mini&&cost+2*i*j+min_[nleft-i*i*j]<mini&&lasthi>=deep&&lastri>=deep){
			    dfs(nleft-i*i*j,deep-1,j,i,cost+2*i*j);				
			}
		}
	}
}
int main()
{
	int m,n,i,j;
	freopen("poj.in","r",stdin);
	freopen("poj.out","w",stdout);
	cin>>n>>m;
	mini=INT_MAX;
	j=1;
	for (i=1;i<=10000;i++){
		min_[i]=int(pow(i,2.0/3)*2);
	} 
	for (i=n;i>0;i--){
		for (j=n/(i*i);j>0;j--) 
			if (i*i+2*i*j+min_[n-i*i*j]<mini&&i>=m&&j>=m)dfs(n-i*i*j,m-1,j,i,i*i+2*i*j);				
	} 
	if (mini==INT_MAX) cout<<0;else cout<<mini;
	fclose(stdin);
	fclose(stdout);
} 
