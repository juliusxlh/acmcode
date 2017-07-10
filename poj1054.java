import java.util.*;
import java.io.*;
class frog
{
	int x;
	int y;
	public void forg(){
		this.x=0;
		this.y=0;
	}
}
public class poj1054 {
	static frog[] q=new frog[5001];
	static boolean cop(frog a,frog b)
	{
		if (a.x<b.x) return true;
		if (a.x==b.x&&a.y<b.y) return true;
		return false;
	}
	static void swap(int a,int b)
	{
		frog c;
		c=q[a];
		q[a]=q[b];
		q[b]=c;
	}
	static void sort(int x,int y)
	{
		int i=x;
		int j=y;
		frog mid=q[(i+j)/2];
		while (i<j) {
			while (cop(q[i],mid)) i++;
			while (cop(mid,q[j])) j--;
			if (i<=j) {
				swap(i,j);
				i++;
				j--;
			}
		}
		if (i<y) sort(i,y);
		if (j>x) sort(x,j);
	}
	public static void main(String args[]) throws Exception
	{
		File cin =new File("frog.25.in");
		Scanner sc=new Scanner(cin);
		int n=sc.nextInt();
		int m=sc.nextInt();
		int numfrog=sc.nextInt();
		for (int i=0;i!=numfrog;i++) q[i]=new frog();
		short[][] f=new short[n+1][m+1];
		for (int i=0;i!=numfrog;i++) {
			q[i].x=sc.nextInt();
			q[i].y=sc.nextInt();
		}
		sort(0,numfrog-1);
		for (int i=0;i!=numfrog;i++) {
			f[q[i].x][q[i].y]=(short)(i+1);
		}
		int maxans=2;
		for (int i=0;i!=numfrog;i++) {
			for (int j=i+1;j!=numfrog;j++) {
				int sum=2;
				int dx=q[j].x-q[i].x;
				int dy=q[j].y-q[i].y;
				int stx=q[i].x-dx;
				int sty=q[i].y-dy;
				if (stx>=1&&sty>=1&&sty<=m) continue;
				if (q[i].x+dx*(maxans-1)<1||q[i].x+dx*(maxans-1)>n) continue;
				if (q[i].y+dy*(maxans-1)<1||q[i].y+dy*(maxans-1)>m) continue;
				stx=q[j].x+dx;
				sty=q[j].y+dy;
				boolean flag=true;
				while (stx>0&&stx<=n&&sty>0&&sty<=m) {
					if (f[stx][sty]==0) {
						flag=false;
						break;
					}
					stx=stx+dx;
					sty=sty+dy;
					sum++;
				}
				if (flag&&sum>maxans) maxans=sum; 
			}
		}
		if (maxans>=3) System.out.printf("%d\n", maxans);else System.out.printf("0\n");
		sc.close();
	}
}
