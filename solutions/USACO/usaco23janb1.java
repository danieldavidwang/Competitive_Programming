import java.io.*;
import java.util.*;

public class MainS3Leaders {
	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	
	static int N;
	static int[] cows;
	static int[] leader;
	static int gmin=-1, gmax, hmin=-1, hmax;
	static int[] notes;
	
	public static void main(String[] args) throws IOException {
		try {
			N = readInt();
			cows = new int[N+1];
			leader = new int[N+1];
			notes = new int[N+1];
			
			
			String str = next();
			for(int i=1; i<=N; i++) {
				cows[i] = (str.charAt(i-1)=='G'?1:2);
				if(cows[i]==1) {
					if(gmin==-1) { gmin=gmax=i; }
					else gmax=i;
				} else {
					if(hmin==-1) { hmin=hmax=i; }
					else hmax=i;
				}
			}
			
			for(int i=1; i<=N; i++) {
				notes[i] = readInt();
				if(cows[i]==1 && i<=gmin && notes[i]>=gmax) {
					leader[i]=1;
					for(int j=1; j<i; j++) {
						if(cows[j]==2 && notes[j]>=i) leader[j]=2;
					}
				}
				else if(cows[i]==2 && i<=hmin && notes[i]>=hmax) {
					leader[i]=2;
					for(int j=1; j<i; j++) {
						if(cows[j]==1 && notes[j]>=i) leader[j]=1;
					}
				}
			}

			int gl = 0, hl = 0;
			for(int i=1; i<=N; i++) {
				if(leader[i]==1) gl++;
				else if(leader[i]==2) hl++;
			}
			out.println(gl*hl);
			
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