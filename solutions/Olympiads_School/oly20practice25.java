import java.util.*;
import java.io.*;


public class MainS3Hackathon {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	
	static int N, K;
	
	public static void main(String[] args) throws IOException {        
		try {
			N = readInt(); K = readInt();
			
			for (int i = 0; i<K; i++){
				int s = readInt(), t = readInt(), r = readInt();
				int ans = 0, workingTime = 0;
				for(int j=0; j<N; ) {
					j += s;
					ans++; workingTime++;
					if(workingTime % t == 0 && j<N) ans += r;
				}
				pr.println(ans);
			}
			
			
		} finally {
			pr.flush();
			pr.close();
		}
	}
		
	
	static String read () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(read());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(read());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(read());
	}
	static char readChar () throws IOException {
		return read().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
	    
}