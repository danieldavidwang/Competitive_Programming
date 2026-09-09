import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;

public class MainJamesRectangles {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	
	static int N=0;
	static double x[], y[];
	static HashMap<String, Integer> cnt = new HashMap<String, Integer>();
	static long ans=0;
	
	
	public static void main(String[] args) throws IOException {
		try {
			N = readInt();
			x = new double[N]; y = new double[N];
			for(int i=0; i<N; i++) {
				x[i] = readDouble();
				y[i] = readDouble();
			}
			
			for(int i=0; i<N-1; i++) {
				for(int j=i+1; j<N; j++) {
					double s = Math.pow(x[i]-x[j], 2)+ Math.pow(y[i]-y[j], 2);
					double x0 = (x[i] + x[j])/2;
					double y0 = (y[i] + y[j])/2;
					String k = s+","+x0+","+y0;
					if(!cnt.containsKey(k)) cnt.put(k, 1);
					else {
						int v = cnt.get(k);
						ans += v;
						cnt.put(k, v+1);
					}
				}
			}
			
			out.println(ans);
			
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