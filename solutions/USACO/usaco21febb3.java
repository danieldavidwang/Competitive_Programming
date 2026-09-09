import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;


public class MainS3ClockwiseFence {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	
	static final String CW="CW", CCW="CCW";
	static final HashSet<String> cwSet = new HashSet<>(Arrays.asList("WN", "NE", "ES", "SW"));
	static final HashSet<String> ccwSet = new HashSet<>(Arrays.asList("NW", "EN", "SE", "WS"));
	static int N=0;

	public static void main(String[] args) throws IOException {
		try {
			N = readInt();
			
			
			for(int i=0; i<N; i++) {
				String str = next();
				
				int cwCnt = 0, ccwCnt = 0;
				for(int j=0; j<str.length()-1; j++) {
					Character a = str.charAt(j);
					Character b = str.charAt(j+1);
					if(a==b) continue;
					String ab =  ""+a+b;
					if(cwSet.contains(ab)) cwCnt++;
					else if(ccwSet.contains(ab)) ccwCnt++;
				}
				out.println((cwCnt>=ccwCnt)?CW:CCW);
			}
			
		} finally {
			out.flush();
			out.close();
		}
		
	}	//end of main()
	
	
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