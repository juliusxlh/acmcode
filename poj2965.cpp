#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int num,p,q,min,ans,i,j,fp[20],x[5],y[5];
	char ch;
	bool bl;
	freopen("poj.in","r",stdin);
	freopen("poj.out","w",stdout);
	for (i=0;i<16;i++){
		cin>>ch;
		if (ch=='+') fp[i]=1;else
		if (ch=='-') fp[i]=0;
	}
	min=20;
	ans=-1;
	for(i=0;i<65536;i++){
		p=i;
		num=0;
		q=0;
		memset(x,0,4*sizeof(int));
		memset(y,0,4*sizeof(int));
		while (p!=0){
			if (p%2==1){
				x[q%4]++;
				y[q/4]++;
				num++;
			} 
			q++;
			p=p>>1;
		} 
		bl=true;
		for (j=0;j<16;j++){
			if ((x[j%4]+y[j/4]-(i>>j)%2)%2!=fp[j]){
				bl=false;
				break;
			}
		}
		if (bl&&num<min){
			min=num;
			ans=i;
		}
	}
	cout<<min<<endl;
	for (i=0;i<16;i++){
		if ((ans>>i)%2==1) cout<<i/4+1<<' '<<i%4+1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
