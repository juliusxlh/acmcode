#include <stdio.h>
#include <iostream>
#include <iomanip> 
#include <string.h>
#include <cmath> 
using namespace std;
int main()
{
	int fn,casen,n,ed,st,i,j,k,s;
	long long f[10],o,w;
	freopen("poj.in","r",stdin);
	freopen("poj.out","w",stdout);
	cin>>casen;
	k=0;
	while (casen!=0){
		memset(f,0,sizeof(long long)*10);
		k++;
		cout<<"Scenario #"<<k<<':'<<endl;
		casen--;
		cin>>st>>ed;
		n=ed-st+1;
		ed=st+ed;
		st=ed;
		fn=0;
		if (st%2==0) st=st/2;else n=n/2;
		while (st!=0){
			f[fn++]=st%10000;
			st=st/10000;
		}
		s=0;
		o=0;
		w=0;
		while (s<fn||w!=0){
			o=w+n*(s>=fn?0:f[s]);
			w=o/10000;
			f[s]=o%10000;
			s++;
		}
		if (s==0) {
			cout<<0<<endl<<endl;
			continue;
		}
		cout<<f[s-1];
		for (i=s-2;i>=0;i--) {
		cout<<setw(4)<<setfill('0');
		if (f[i]<0) cout<<-f[i];else cout<<f[i];}
		cout<<endl<<endl;
		
	}
	fclose(stdin);
	fclose(stdout);
} 
