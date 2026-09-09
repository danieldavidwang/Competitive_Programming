import java.io.*;
import java.util.*;

public class MainS3AirCownditioningII_DP {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int N, M;

	public static void main(String[] args) throws IOException {
		try {
			N = readInt(); M = readInt();
			int[] val = new int[102];
			for(int i=1; i<=N; i++) {
				int a = readInt(), b = readInt(), c=readInt();
				for (int j=a; j<=b; j++) val[j] += c;
			}
			int a[] = new int[M], b[] = new int[M], p[] = new int[M], cost[] = new int[M];
			for(int i=0; i<M; i++) {
				a[i] = readInt(); b[i] = readInt(); p[i] = readInt(); cost[i] = readInt();
			}
			int ans = Integer.MAX_VALUE;
			for(int mask =0; mask<1<<M; mask++) {
				int temp[] = new int[102], amount = 0;
				for(int k=0; k<M; k++) {
					if((mask>>k & 1) != 0) {
						amount += cost[k];
						temp[a[k]] += p[k]; temp[b[k]+1] -= p[k];
					}
 				}
				boolean work = true;
				for(int i=1; i<temp.length; i++) {
					temp[i] += temp[i-1];
					if(temp[i] < val[i]) {work = false; break;}
				}
				if(work) ans = Math.min(ans,  amount);
			}
			System.out.println(ans);
			
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