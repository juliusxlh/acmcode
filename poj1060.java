import java.util.*;
import java.io.*;
public class poj1060 {
	static int maxi=2010;
	static int[] f=new int[maxi];
	static int[] g=new int[maxi];
	static int[] h=new int[maxi];
	static int[] p=new int[maxi];
	public static void main(String args[]) throws Exception{
		File cin = new File("poj.in");
		Scanner sc=new Scanner(cin);
		int n=sc.nextInt();
		while (n--!=0) {
			for (int i=0;i!=maxi;i++) {
				f[i]=0;
				g[i]=0;
				h[i]=0;
				p[i]=0;
			}
			int degreef=sc.nextInt();
			for (int i=0;i!=degreef;i++) f[degreef-i-1]=sc.nextInt();
			int degreeg=sc.nextInt();
			for (int i=0;i!=degreeg;i++) g[degreeg-i-1]=sc.nextInt();
			int degreeh=sc.nextInt();
			for (int i=0;i!=degreeh;i++) h[degreeh-i-1]=sc.nextInt();
			for (int i=0;i!=degreef;i++) {
				for (int j=0;j!=degreeg;j++)
					p[i+j]=(p[i+j]+f[i]*g[j])%2;
			}
			for (int i=degreef+degreeg-2;i>=0;i--) {
				if (p[i]==1) {
					if (degreeh-2>=i) break;
					for (int j=degreeh-1;j>=0;j--) {
						p[i+j-degreeh+1]=Math.abs((p[i+j-degreeh+1]-h[j])%2);
					}
				}
			}
			int maxorder = 0;
			for (int i=degreeh;i>=0;i--) if (p[i]!=0) {
				maxorder=i;
				break;
			}
			System.out.printf("%d",maxorder+1);
			for (int i=maxorder;i>=0;i--) System.out.printf(" %d",p[i]);
			System.out.println();
		}
		sc.close();
	}
}
