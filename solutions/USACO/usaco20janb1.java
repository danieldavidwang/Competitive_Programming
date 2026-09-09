import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class MainS3WordProcessor {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	
	static int N=0, K=0;
	static String inp[];
	static StringBuilder essay = new StringBuilder();
	
	public static void main(String[] args) throws IOException {
		try {
			N = readInt();
			K = readInt();
			inp = new String[N];
			for(int i=0; i<N; i++) inp[i] = next();
		
			int sum = 0;
			for(int i=0; i<N; i++) {
				String str = inp[i];
				int ln = str.length();
				if(sum+ln <= K) {
					if(i>0) essay.append(' ');
					essay.append(str);
					sum += ln;
				} else {
					essay.append('\n');
					essay.append(str);
					sum = ln;
				}
			}
			out.println(essay);
			
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