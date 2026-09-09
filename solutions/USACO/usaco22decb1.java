import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class MainS3CowCollege_frequencyTable {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	
	static final int MAXC = 1000005;
	static int N=0;
	static int[] freq = new int[MAXC];
	
	public static void main(String[] args) throws IOException {
		try {
			N = readInt();
			for(int i=1; i<=N; i++) freq[readInt()]++;
			int cnt = 0;
			long maxAmount = 0, amount = 0;
			int maxC = 0;
			for(int i=1; i<=1000000; i++) {
				if(freq[i]==0) continue;
				amount = (long)i*((long)(N-cnt));
				if(amount > maxAmount) {
					maxAmount = amount;
					maxC = i;
				}
				cnt += freq[i];
			}
			out.println(maxAmount+" "+maxC);
			
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