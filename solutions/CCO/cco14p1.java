import java.io.*;
import java.util.*;

public class MainS3Troyangles {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int N;
	static boolean[][] grid;
	static int[][] dp;
	static int[][] psa;
	
	public static void main(String[] args) throws IOException {
		try {
			N = readInt();
			grid = new boolean[N+1][N+1];
			psa = new int[N+1][N+1];
			dp = new int[N+1][N+1];
			
			for(int i=1; i<=N; i++) {
				String str = next();
				int seq = 0;
				for (int j=1; j<=N; j++) {
					char c = str.charAt(j-1);
					grid[i][j] = (c=='#');
					if(grid[i][j]) {
						seq++;
						psa[i][j] = seq;
						dp[i][j]=1;
					} else seq = 0;
				}
			}
			for(int i=1; i<=N; i++) {
				for (int j=1; j<=N; j++) {
					if(!grid[i][j]) continue;
					int h = (psa[i][j]+1)/2;
					dp[i][j] += Math.min(dp[i-1][j-1], h-1);
				}
			}			

			long ans = 0;
			for(int i=1; i<=N; i++)
				for (int j=1; j<=N; j++) ans += dp[i][j];
			out.println(ans);
			
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