import java.io.*;
import java.util.*;

public class Main {
	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException {
		try {
			int T = readInt();
			for (int t = 0; t < T; t++) {
				int N = readInt(); int K = readInt(); int W = readInt();
				int[] h = new int[N+1];
				for (int i=1; i<=N; i++) h[i] = readInt();
				
				int[] score = new int[N+1];
				for (int i = 1; i <= N; i++) 
					for (int j = 0; j < W && i-j > 0; j++) 
						score[i] += h[i-j];
				
				int[][] dp = new int[K+1][N+1];
				for (int i = 1; i <= N; i++) dp[1][i] = Math.max(dp[1][i-1], score[i]);
				for (int b = 2; b <= K; b++) {
					int tmpMax = 0;
					for (int i = 1; i <= N; i++) {
						if (i <= W) { dp[b][i] = dp[b-1][i]; continue; }
						int ns = score[i]+dp[b-1][i-W];
						dp[b][i] = Math.max(ns,dp[b-1][i-1]);
						tmpMax = Math.max(tmpMax,dp[b][i]);
						dp[b][i] = tmpMax;
					}
				}
				out.println(dp[K][N]);
			}
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