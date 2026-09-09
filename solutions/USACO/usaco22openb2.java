import java.io.*;
import java.util.*;


public class MainS3CountingLiars {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException {
		try {
			int N = readInt();
			ArrayList<Integer> lArr = new ArrayList<Integer>();
			ArrayList<Integer> gArr = new ArrayList<Integer>();


			for(int i=0; i<N; i++) {
				String a = next();
				int b = readInt();
				if(a.equals("L")) lArr.add(b);
				else gArr.add(b);
			}
			Collections.sort(lArr);  Collections.sort(gArr);
			
			int ans = Integer.MAX_VALUE;
			for(int k=1; k<=lArr.size(); k++) {
				int c = lArr.get(k-1);
				int cnt = 0;
				for(int i=1; i<k; i++) {
					if(lArr.get(i-1)<c) cnt++;
					else break;
				}
				for(int i=gArr.size(); i>=1; i--) {
					if(gArr.get(i-1)>c) cnt++;
					else break;
				}
				ans = Math.min(ans, cnt);
			}
			

			for(int k=1; k<=gArr.size(); k++) {
				int c = gArr.get(k-1);
				int cnt = 0;
				for(int i=1; i<=lArr.size(); i++) {
					if(lArr.get(i-1)<c) cnt++;
					else break;
				}
				for(int i=gArr.size(); i>=k; i--) {
					if(gArr.get(i-1)>c) cnt++;
					else break;
				}
				ans = Math.min(ans, cnt);
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