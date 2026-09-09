import java.io.*;
import java.util.*;

public class C7Q1 {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	
	static int N=0;
	static ArrayList<Integer> eArr; 
	static ArrayList<Integer> oArr;
	

	public static void main(String[] args) throws IOException {
		try {
			N = readInt();
			eArr = new ArrayList<>();
			oArr = new ArrayList<>();
			
			long ep1=0, ep2=0;
			long op=0; 
			long p = 0;
			int a = 0;
			for(int i=1; i<=N; i++) {
				a = readInt();
				if ((a & 1) == 0) {
					eArr.add(i);
					ep1 += a/2-1;
					ep2 += a/2;
				}
				else {
					oArr.add(i);
					op += (a-1)/2;
				}
			}
			
			boolean case1 = false;
			if(oArr.size()>0) {
				//there is at least 1 odd page
				case1 = true;
				p = op+ep1;
			} else {
				//there is no odd page
				case1 = false;
				p = op+ep2;
			}
			
			StringBuilder ans = new StringBuilder();
			if(case1) {
				ans.append(oArr.get(0)).append(' ');
				for(Integer it : eArr) ans.append(it).append(' ');
				for(int i=1; i<oArr.size(); i++) {
					ans.append(oArr.get(i)).append(' ');
				}
			} else {
				for(Integer it : eArr) ans.append(it).append(' ');
			}
			
			
			out.println(p);
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