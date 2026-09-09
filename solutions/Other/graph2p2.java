import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static final int MAX = 1000;
	static int N;
	static int[][] adj = null;
	static int[] visited = null;
	static int[] dis = null;
	static boolean acyclic = true;

	public static void main(String[] args) throws IOException {
		try {
			N = readInt();
			adj = new int[N][N];
			visited = new int[N];
			dis = new int[N];
			
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					adj[i][j]=readInt();
				}
			}
			for(int i=0; i<N; i++) {
				if(visited[i]==0) {
					dfs(i);
					if(!acyclic) {
						out.println("NO");
						return;
					}
				}
			}
			out.println("YES");
			
		} finally {
			out.flush();
			out.close();
		}
		
	}
	
	static void dfs(int cur) {
		visited[cur] = 1;
		
		for(int i=0; i<N; i++) {
			if(adj[cur][i]==1) {
				if(visited[i]==1) {
					acyclic = false;
				}
				else if(visited[i]==0) {
					dis[i] = dis[cur]+1;
					dfs(i);
				} 
			}
		}
		visited[cur] = 2;
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