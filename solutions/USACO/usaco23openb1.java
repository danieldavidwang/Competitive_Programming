import java.io.*;
import java.util.*;


public class MainS3Dominos {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	
	static int N;
	static int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;

	public static void main(String[] args) throws IOException {
		try {
			N = readInt();
			char s[] = readLine().toCharArray();
			if(s[0] == 'F') {
				s[0] = 'B'; check(s);
				s[0] = 'E'; check(s); s[0] = 'F';
			} else {
				check(s);
			}
			
			int d = (s[0] == 'F' || s[s.length-1] == 'F') ? 1:2;
			out.println((max - min)/d +1);
			for(int i=min; i<=max; i+=d) out.println(i);
			
		} finally {
			out.flush();
			out.close();
		}
	}
	
	static void check(char s[]) {
		char[] a = Arrays.copyOf(s, s.length);
		int cnt = 0;
		for(int i=1; i<a.length; i++) {
			if(a[i] == 'F') a[i] = (a[i-1] == 'B'?'E' : 'B');
			if(a[i] == a[i-1]) cnt++;
		}
		min = Math.min(min,  cnt);
		a = Arrays.copyOf(s,  s.length); cnt = 0;
		for(int i=1; i<a.length; i++) {
			if(a[i] == 'F') a[i] = a[i-1];
			if(a[i] == a[i-1]) cnt++;
		}
		max = Math.max(cnt, max);
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