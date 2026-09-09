import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class MainS3SocialDistancingI {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	
	static int N=0;
	static String inp;
	
	public static void main(String[] args) throws IOException {
		try {
			N = readInt();
			inp = next();
			
			int maxDis1 = Integer.MIN_VALUE;
			int maxDis2 = Integer.MIN_VALUE;
			int minDis = Integer.MAX_VALUE;
			int leftSpace = 0, rightSpace = 0;
			int st=0;
			for(int i=1; i<N; i++) {
				char c = inp.charAt(i);
				if(c=='1' || i==(N-1)) {
					int dis = i - st;
					if(maxDis1<=dis) {
						maxDis2 = maxDis1;
						maxDis1 = dis;
					}
					
					if(st==0 && inp.charAt(0)=='0') leftSpace = dis;
					if(i==N-1 && c=='0') rightSpace = dis;
					if(c=='1' && st>0 && minDis>dis) minDis = dis;
					st = i;
				}
			}
			//System.out.println("maxDis1="+maxDis1+"; maxDis2="+maxDis2+"; minDi1="+minDis+"; leftSpace="+leftSpace+"; rightSpace="+rightSpace);
			
			int ans = 0;
			int a = maxDis1/3;
			int b = maxDis1/2;	//max in a, b, c.
			int c = maxDis2/2;
			if(leftSpace >= b && rightSpace >= b) {
				ans = Math.min(leftSpace, rightSpace);
				ans = Math.min(ans, minDis);
			} else if(leftSpace >= b || rightSpace >= b) {
				ans = Math.min(b, minDis);
			}  else {
				if(a>=c) ans = Math.min(a, minDis);
				else ans = Math.min(c, minDis);
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