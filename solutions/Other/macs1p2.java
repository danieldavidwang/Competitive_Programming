import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class MainS3Enraged {
	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N;

	public static void main(String[] args) throws IOException {
		try {
			N = readInt();
			String s1 = next();
			String s2 = next();
			int cnt = 0;
			for(int i=0; i<N; i++) {
				if(s1.charAt(i)=='S' && s2.charAt(i)=='S') cnt++;
			}
			if(cnt>2) out.println("NO");
			else out.println("YES");
			
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