import java.io.*;
import java.util.*;


public class MainS3Photoshoot {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		try {
			int N = readInt();
			String str = next();
			ArrayList<Boolean> strPair = new ArrayList<Boolean>();
			String pair = "";
			for(int i = 0; i<N; i++) {
				char c =str.charAt(i);
				pair += c;
				if(pair.length()==2) {
					if(pair.equals("GH")) strPair.add(false);
					else if(pair.equals("HG")) strPair.add(true);
					pair = "";
				}
			}
			//out.println(strPair);
			
			ArrayList<Boolean> simplifiedPair = new ArrayList<Boolean>();
			simplifiedPair.add(strPair.get(0));
			for(int i = 1; i<strPair.size(); i++) {
				boolean cur = strPair.get(i);
				if(simplifiedPair.get(simplifiedPair.size()-1) != cur)
					simplifiedPair.add(cur);
			}
			
			int ans = simplifiedPair.size();
			if(simplifiedPair.get(simplifiedPair.size()-1)) ans--;
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