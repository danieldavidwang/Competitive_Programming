import java.util.ArrayList;
import java.util.Scanner;
import java.util.SortedMap;
import java.util.SortedSet;
import java.util.TreeMap;

public class MainPrimeTime_CountingArray {

	public static void main(String[] args) {
		final int MAX = 5;
		int[] ans = null;
		
		Scanner scan = new Scanner(System.in); 
		int N = 0;
		
		for (int i=0; i<MAX; i++) {	
			N = scan.nextInt();
			ans = new int[100001];
			
			for(int m=N; m>1; m--) {
				int r = 0;
				int e = 0;
				int t = 0;
				
				int q = m;
				for (int j=2; j<=m; j++) {
					if(ans[j]>0 || ans[j]==-1) continue;
					
					r = q % j;
					t = 0;
					e = 0;
					if (r==0) {
						t = N/j;
						while (t>0) {
							e += t;
							t = t/j;
						}
						ans[j] += e;
						q = q/j^e;
						
						for (int z=2; z<=(10001/j); z++)
						{
							ans[j*z] = -1;
						}
					}
				}
			}

			int cnt = 0;
			for (int y=1; y<=10001; y++)
			{
				if (ans[y]>0) {
					if(cnt > 0) System.out.print(" * ");
					System.out.print(y +"^"+ ans[y]);
					cnt ++;
				}
			}
			System.out.println("\n");	
		}
	}
}