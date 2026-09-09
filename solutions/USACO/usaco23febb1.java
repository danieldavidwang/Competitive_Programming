import java.io.*;
import java.util.*;

public class MainS3HungryCow {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	
	static int N;
	static long T;

	public static void main(String[] args) throws IOException {
		try {
			N = readInt();
			T = readLong();
			
			long hay = 0, bank=0;
			long pre_day = 0;
			for(int i=0; i<N; i++) {
				long day = Math.min(T, readLong());
				long dif_day = day-pre_day-1;
				long dif_hay = Math.min(bank-hay, dif_day)+1;
				hay += dif_hay;
				bank += readLong();
				pre_day = day;
				if(day==T) {
					out.println(hay); return;
				}
			}
			long tmp = Math.min(bank-hay, T-pre_day);
			hay = Math.min(hay+tmp, T);
			out.println(hay);
			
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