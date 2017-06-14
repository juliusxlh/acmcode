#include <stdio.h>
#include <iostream>
bool bp[40000];
int prime[20000];
using namespace std;
int main()
{
	bool bl;
	int sum,n,st,i,j;
	freopen("poj.in","r",stdin);
	freopen("poj.out","w",stdout);
	st=1;
	prime[0]=2;
	bp[2]=1;
	for (i=3;i<40000;i++){
		bl=true;
		for (j=0;j<st;j++){
			if (prime[j]*prime[j]>i) break;
			if (i%prime[j]==0){
				bl=false;
				break;
			}
		}
		if (bl){
			prime[st]=i;
			bp[i]=1;
			st++;
		}
	}
	while (1){
		cin>>n;
		if (n==0) break;
		sum=0;
		for (i=0;i<st;i++)
		    if (prime[i]<=(n/2)&&bp[n-prime[i]]) sum++;
		cout<<sum<<endl;
	} 
	fclose(stdin);
	fclose(stdout);
} 
