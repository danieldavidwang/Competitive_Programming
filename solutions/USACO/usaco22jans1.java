import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;


public class MainS3Review_SoulMate {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	
	static int N;
	
	public static void main(String[] args) throws IOException {
		try {
			N = readInt();
			for(int k=0; k<N; k++) {
				long x = readLong();
				long y = readLong();
				if(x == y) { out.println(0); continue;}
				long cnt = 0, ans = Long.MAX_VALUE;
				
				while(y >= 1) {
					if(x > y) {
						if(x % 2 != 0) {
							x++; cnt++;
						}
						x /= 2;  cnt++;
					} else if(x < y) {
						long tmp = cnt + (y-x);
						if(tmp > ans) break;
						ans = tmp;
						if(y % 2 != 0) {
							y--; cnt++;
						}
						y/=2; cnt++;
					} else {
						ans = Math.min(ans, cnt);
						break;
					}
				}
				out.println(ans);
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