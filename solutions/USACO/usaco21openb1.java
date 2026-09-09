import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;


public class MainS3AcowdemiaI_v2 {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	
	static int N=0, L=0;
	static int ci[];

	public static void main(String[] args) throws IOException {
		try {
			N = readInt();
			L = readInt();
			ci = new int[N];
			for(int i=0; i<N; i++) ci[i] = readInt();

			long lo = 0, hi = N, ans = 0;
	    	while(lo <= hi) {
	    		long mid = (lo + hi)/2;
	    		if(check(mid)) { ans = mid; lo = mid + 1; }
	    		else hi = mid - 1;
	    	}
	    	out.println(ans);
			
		} finally {
			out.flush();
			out.close();
		}
		
	}
	
	static boolean check(long num) {
    	long cnt = 0;
    	int tmp = L;
    	for(int i=0; i<N; i++) {
    		if(ci[i] >= num) cnt++;
    		else if(ci[i]==num-1) {
    			if(tmp>0) {
    				cnt++;
    				tmp--;
    			}
    		}
    		if(cnt >= num) return true;
    	}
    	return false;
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