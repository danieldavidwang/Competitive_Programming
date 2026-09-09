import java.io.*;
import java.util.*;


public class MainS3MilkSum {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws IOException {
		try {
			int N = readInt();
			ArrayList<Long> arr0 = new ArrayList<Long>();
			ArrayList<Long> arr = new ArrayList<Long>();
			long T0 = 0;
			for(int i=1; i<=N; i++) {
				long a = readLong();
				arr0.add(a); arr.add(a);
			}
			Collections.sort(arr);
			long[] psa = new long[N+1];
			for(int i=0; i<N; i++) {
				T0 += (i+1)*arr.get(i);
				psa[i+1] = psa[i]+arr.get(i);
			}
			
			int Q = readInt();
			for(int k=1; k<=Q; k++) {
				int x = readInt();
				long y = readLong();
				long s = arr0.get(x-1);
				if(s==y) {
					sb.append(T0).append('\n');
					continue;
				} else if(y>s) {
					long t1 = T0;
					int l = Collections.binarySearch(arr, s);
					int r = Collections.binarySearch(arr, y);
					if(r<0) {
						r = Collections.binarySearch(arr, y);
						r = -r - 1;
					}
					r--;
					
					if(l==r) {
						t1 += (y-s)*(r+1);
					} else {
						t1 -= (psa[r+1] - psa[l+1]);
						t1 -= s*(l+1);
						t1 += y*(r+1);
					}
					
					sb.append(t1).append('\n');
					continue;
				} else {
					long t1 = T0;
					int r = Collections.binarySearch(arr, s);
					int l = Collections.binarySearch(arr, y);
					if(l<0) {
						l = Collections.binarySearch(arr, y);
						l = -l -1;
					} else l++;
					
					if(l==r) {
						t1 -= (s-y)*(r+1);
					} else {
						t1 += psa[r] - psa[l];
						t1 -= s*(r+1);
						t1 += y*(l+1);
					}
					
					//out.println(t1);
					sb.append(t1).append('\n');
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