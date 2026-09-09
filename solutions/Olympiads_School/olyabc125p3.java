import java.io.*;
import java.util.*;

public class MainS3MaxGCD_gcd_lcm {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException {
		try {
			int N = readInt();
			int arr[] = new int[N];
			for(int i=0; i<N; i++) arr[i] = readInt();
			if(N==2) {
				out.println(Math.max(arr[0], arr[1]));
				return;
			}
			
			long lgcd = 0, rgcd = 0;
			long[][] gcdlist = new long[N][2];
			for(int i=0; i<N; i++) {
				if(lgcd == 0) lgcd = arr[i];
				else lgcd = gcd(lgcd, arr[i]);
				
				if(rgcd == 0) rgcd = arr[N-1-i];
				else rgcd = gcd(rgcd, arr[N-1-i]);
				
				gcdlist[i][0] = lgcd;
				gcdlist[N-1-i][1] = rgcd;
			}

			long ans = Math.max(gcdlist[1][1], gcdlist[N-2][0]);
			for(int i=1; i<N-1; i++) {
				ans = Math.max(ans, gcd(gcdlist[i-1][0], gcdlist[i+1][1]));
			}
			out.println(ans);

		} finally {
			out.flush();
			out.close();
		}
		
	}
	

    static long lcm(long x, long y) {
    	return x/gcd(x, y) * y;
    }
    static long gcd(long x, long y) {
    	return y==0?  x : gcd(y, x % y);
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