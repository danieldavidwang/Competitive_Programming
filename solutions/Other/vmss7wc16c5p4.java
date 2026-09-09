import java.io.*;
import java.util.*;

public class Main {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int N, X, Y, Z;
	static int[] xyz = new int[3];
			
	public static void main(String[] args) throws IOException {
		try {
			N = readInt();
			xyz[0] = readInt();
			xyz[1] = readInt();
			xyz[2] = readInt();
			Arrays.sort(xyz);
			
			if ((N % xyz[0]) == 0) { out.println(N/xyz[0]); return; }
			else {
				int cnt1 = cntTwo(N, xyz[1], xyz[0]);
				int cnt2 = cntTwo(N, xyz[2], xyz[0]);
				int cnt3 = cntTwo(N, xyz[2], xyz[1]);
				int ans = Math.max(Math.max(cnt2, cnt3), cnt1);
				if (ans > 0) { out.println(ans); return; }
				else {
					cnt1 = 0; cnt2 = 0;
					for (int s=N-xyz[2]; s>=0; s -= xyz[2]) {
						cnt1++;
						cnt2 = cntTwo(s, xyz[1], xyz[0]);
						if (cnt2>0) {
							ans = cnt1+cnt2;
							out.println(ans); return;
						}
					}
				}
				
			}
			
		} finally {
			out.flush();
			out.close();
		}
		
	}
	
	static int cntTwo(int m, int a, int b) {
		int ret = 0, cnt = 0;
		for(int s=m-a; s>=0; s-=a) {
			cnt++; 
			if((s % b) == 0) {
				cnt += s/b;
				ret = cnt;
				break;
			}
		}
		return ret;
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