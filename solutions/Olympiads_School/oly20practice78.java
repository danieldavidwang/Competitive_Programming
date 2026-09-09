import java.io.*;
import java.util.*;

public class MainS3AppleShopping_DP {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int N, M;
	static int[] dp;
	
	public static void main(String[] args) throws IOException {
		try {
			N = readInt(); M = readInt();
			dp = new int[M+1];
			Arrays.fill(dp, Integer.MAX_VALUE);
			dp[0] = 0;
					
			int[][] vw = new int[N+1][2];
			for(int i=1; i<=N; i++) {
				vw[i][0] = readInt(); vw[i][1] = readInt();
			}
			
			for(int i=1; i<=M; i++) {
				for(int j=1; j<=N; j++) {
					int vj = vw[j][0], wj = vw[j][1];
					int b = 0;
					if(i >= vj) b = (dp[i-vj]==Integer.MAX_VALUE)? 0 : dp[i-vj];
					dp[i] = Math.min(dp[i], b+wj);
				}
			}

			out.println(dp[M]);
			
		} finally {
			out.flush();
			out.close();
		}
		
	}
	
	
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