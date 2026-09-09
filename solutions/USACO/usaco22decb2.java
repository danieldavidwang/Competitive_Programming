import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class MainS3FeedingCows {

	static final char EMPTY = '\u0000';
	static PrintWriter wrt = new PrintWriter(System.out);
	static BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer stk;
	static int T=0, N=0, K=0;
	static String inp;
	static boolean arr[][];
	static char ret[];
	
	public static void main(String[] args) throws IOException {
		T = nextInt();
		for(int t=0; t<T; t++) {
			N = nextInt();
			K = nextInt();
			inp = next();
			if(K==0) {
				wrt.println(N);
				wrt.println(inp);
				continue;
			}
			ret = new char[N];
			arr = new boolean[N][2];
			for(int i=0; i<N; i++) {
				char c = inp.charAt(i);
				int type = ((c=='G')?0:1);
				
				if(arr[i][type]) continue;
				else {
					int left = Math.max(0, i-K);
					int right = Math.min(i+K, N-1);
					for(int p=right; p>=left; p--) {
						if(ret[p]==EMPTY) {
							ret[p]=c;
							for(int q=Math.max(0, p-K); q<=Math.min(p+K, N-1); q++) arr[q][type] = true;
							break;
						}
					}
				}
			}
			StringBuilder str = new StringBuilder();
			int ans = 0;
			for(int i=0; i<N; i++) {
				if(ret[i]==EMPTY) str.append('.');
				else {
					ans++;
					str.append(ret[i]);
				}
			}
			str.insert(0, '\n');
			str.insert(0, ans);
			wrt.println(str);
			wrt.flush();
		}
		wrt.close();
	}
	
	static String next () throws IOException {
		while (stk == null || !stk.hasMoreTokens())
			stk = new StringTokenizer(rd.readLine().trim());
		return stk.nextToken();
	}
	static long nextLong () throws IOException {
		return Long.parseLong(next());
	}
	static int nextInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double nextDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static String nextLine () throws IOException {
		return rd.readLine().trim();
	}
}