import java.io.*;
import java.util.*;

public class Main {
	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		try {
			int N = readInt(); long A = readLong(); long B = readLong();
			
			if(N==1) {
				out.println(A+B); return;
			}
			
			if(A==B) {
				long tmp = A*2;
				int cnt = 1, layer=1;
				while (cnt<N) {
					layer++;
					if(cnt+layer<=N) {
						tmp += A*(layer+1)*layer;
						cnt += layer;
					} else {
						int d = N-cnt;
						tmp += A*(layer+1)*d;
						cnt += d;
						break;
					}
				}
				out.println(tmp);
				return;
			}
			
			if( (A>B && A/B==1) || (A<B && B/A==1) ) {
				int k = (int)Math.ceil(Math.sqrt(N*2))*2;
				PriorityQueue<Long> que = new PriorityQueue<Long>();
				for(int i=1; i<=k; i++) {
					for(int j=1; j<=k; j++) {
						que.add(A*i+B*j);
					}
				}
				
				long ans = 0;
				for(int i=0; i<N; i++) ans += que.poll();
					
				out.println(ans);
				return;
			}
			if( (A>B && A/B>=N) || (A<B && B/A>=N) ) {
				PriorityQueue<Long> que = new PriorityQueue<Long>();
				long mx = Math.min(A*N+B, A+B*N);
				int fl = 1, rm = 1;
				while(true) {
					if(fl>N || fl*A>mx) break;
					long x = A*fl + B*rm;
					if(x > mx) {
						fl++; rm=1;
					} else {
						que.add(x);
						rm++;
					}
				}
				
				long ans = 0;
				for(int i=0; i<N; i++) ans += que.poll();
					
				out.println(ans);
			} else {
				long d = (A>B? A/B : B/A);
				if(d<=10) {
					int k = (int)Math.ceil(Math.sqrt(N*2/d))*15;
					PriorityQueue<Long> que = new PriorityQueue<Long>();
					for(int i=1; i<=k; i++) {
						for(int j=1; j<=k; j++) {
							que.add(A*i+B*j);
						}
					}
	
					long ans = 0;
					for(int i=0; i<N; i++) ans += que.poll();
					out.println(ans);
					return;
				} else {
					int k = (int)(Math.sqrt(N*(N+1)/d)+1);
					PriorityQueue<Long> que = new PriorityQueue<Long>();
					for(int i=1; i<=k; i++) {
						for(int j=1; j<=k/(i*d)+100; j++) {
							if(A<B) que.add(A*i+B*j);
							else que.add(A*i+B*j);
						}
					}
					
					long ans = 0;
					for(int i=0; i<N; i++) ans += que.poll();
					out.println(ans);
					return;
				}
			}
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