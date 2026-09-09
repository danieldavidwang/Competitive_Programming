import java.io.*;
import java.util.*;



public class MainS3MooOperations {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	
	static int Q;
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws IOException {
		try {
			Q = readInt();
			for(int i=0; i<Q; i++) {
				String s = next();
				if(s.length()<3) {
					sb.append(-1).append("\n");
					continue;
				} else {
					int l = s.length();
					if(s.indexOf("MOO") >= 0) sb.append(l-3).append("\n");
					else if(s.indexOf("OOO") >= 0 || s.indexOf("MOM") >= 0) sb.append(l-2).append("\n");
					else if(s.indexOf("OOM") >= 0) sb.append(l-1).append("\n");
					else sb.append(-1).append("\n");
					continue;
				}
			}
			out.println(sb);
			
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