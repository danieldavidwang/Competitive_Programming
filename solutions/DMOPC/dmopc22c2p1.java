import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class MainCompQ1_DMOPCCrisis_v3 {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	
	static int N=0, M=0;
	static char[] ans = null;
	
	public static void main(String[] args) throws IOException {
		try {
			N = readInt();
			ans = new char[N];
			if(N==3) {
				out.println(1);
				out.println("__M");
				return;
			}
			if(N==4) {
				out.println(2);
				out.println("_MM_");
				return;
			}
			if(N==5) {
				out.println(2);
				out.println("___MM");
				return;
			}
			if(N==6) {
				out.println(2);
				out.println("____MM");
				return;
			}
			
			int cnt = 0;
			ans[0]='_';
			char last ='_';
			for(int i=1; i<N; i++) {
				if(i<=N-2) {
					ans[i]='M';
					cnt++;
					i++;
				} else if (i==N-1) {
					ans[i]='_';
					i++;
					break;
				}
				
				if(i<=N-2) {
					ans[i]='M';
					cnt++;
					i++;
				} else if (i==N-1) {
					ans[i]='_';
					i++;
					break;
				}
				
				if(i<N) {
					ans[i]='_';
					i++;
				}
				
				if(i<N) {
					ans[i]='_';
				}
			}
			
			out.println(cnt);
			for(int i=0; i<N; i++) out.print(ans[i]);
			
		} finally {
			out.flush();
			out.close();
		}
		
	}	//end of main()
	
	
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}

	
}