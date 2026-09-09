import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class MainS3AbsolutelyAcidic {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	
	static int N=0;
	static int frq[] = new int[1001];

	public static void main(String[] args) throws IOException {
		try {
			N = readInt();
			for(int i=0; i<N; i++) frq[readInt()]++;
			int[] cpFrq = frq.clone();
			Arrays.sort(cpFrq);
			
			int f1 = cpFrq[1000], f2=cpFrq[999];
			int r1=0, r2=0, ans=0;
			for(int i=1; i<=1000; i++) {
				if(frq[i]==f1) r1 = i;
			}
			for(int i=1; i<=1000; i++) {
				int dif = Math.abs(r1-i);
				if(frq[i]==f2 && ans<dif) ans = dif;
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