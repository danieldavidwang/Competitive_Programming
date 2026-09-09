import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;



public class MainCompBV_20221211_Q4 {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	
	static int N=0, T=0;
	static int inp[];
	static int ans=0;
	
	public static void main(String[] args) throws IOException {
		try {
			N = readInt();
			T = readInt();
			inp = new int[N];
			for(int i=0; i<N; i++) inp[i] = readInt();
			
			if(N==2) {
				if(inp[0]<=T || inp[1]<=T) ans = 1;
				else ans=0;
				System.out.println(ans);
				return;
			}

			long sum = 0;
			int idx = 0, curMax = 0;			
			for(int i=0; i<N; i++) {
				int a = inp[i];			
				if(sum+a <= T) {
					sum += a;
					idx = i;
					curMax = Math.max(curMax, a);
					ans++;
				} else break;
			}

			if(idx==(N-1) || idx==(N-2)) ans = N-1;
			else {
				int tmp = ans;
				sum -= curMax;
				if(tmp>0) tmp--;
				for(int j=idx+1; j<N; j++) {
					int b = inp[j];
					if(sum+b <= T) {
						sum += b;
						tmp++;
					} else break;
				}
				ans = Math.max(ans, tmp);
			}
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