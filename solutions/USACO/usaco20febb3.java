import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.stream.IntStream;

public class MainS3SwapitySwap {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	
	static int N, K, A1, A2, B1, B2;
	static int[] arr;
	static ArrayList<int[]> trans = new ArrayList<int[]>();

	public static void main(String[] args) throws IOException {
		try {
			N = readInt();
			K = readInt();
			A1 = readInt();
			A2 = readInt();
			B1 = readInt();
			B2 = readInt();
			arr = IntStream.range(0, N+1).toArray();

			int[] a = arr.clone();
			while (true) {
				reverse(A1, A2, a);
				reverse(B1, B2, a);
				trans.add(a.clone());
				if(Arrays.equals(arr, a)) break;
			}
			
			int r = K % trans.size();
			int idx = (r==0? trans.size(): r);
			int[] ans = trans.get(idx-1);
			for(int i=1; i<=N; i++) out.println(ans[i]);
			
		} finally {
			out.flush();
			out.close();
		}
		
	}	//end of main()
	
	static void reverse(int st, int ed, int[] arr) {
		for(int i=st; i<=(st+ed)/2; i++) {
			int t = arr[i];
			arr[i] = arr[st+ed-i];
			arr[st+ed-i] = t;
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