import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	static PrintWriter out = new PrintWriter(System.out);
	static FastReader sr = new FastReader();

	static int N=0, R=0;
	static int X=0, Y=0;
	static ArrayList<Integer>[] adj = null;
	static boolean[] visited = null;
	static ArrayList<Integer> bunny = null;
	static ArrayList<Integer> escapePath = new ArrayList<Integer>(); 
	static int ans;
	
	public static void main(String[] args) throws IOException {
		try {
			N = sr.nextInt();
			R = sr.nextInt();
			adj = new ArrayList[N+1];
			visited = new boolean[N+1];
			bunny = new ArrayList<Integer>();
			for(int i=1; i<=N; i++) adj[i] = new ArrayList<Integer>();
			
			for(int i=1; i<N; i++) {
				int a = sr.nextInt();
				int b = sr.nextInt();
				adj[a].add(b);
				adj[b].add(a);
			}
			
			for(int i=0; i<R; i++) 
				bunny.add(sr.nextInt());

			X = sr.nextInt();
			Y = sr.nextInt();
			
			dfs(X,Y, new ArrayList<Integer>());
			bfs();
			out.println(ans);
			
		} finally {
			out.flush();
			out.close();
		}
		
	}
	
	static void dfs(int cur, int end, ArrayList<Integer> arr) {
		visited[cur] = true;
		arr.add(cur);
		
		if (cur == end) {
			escapePath = (ArrayList<Integer>)arr.clone();
        } else {
			for(int i: adj[cur]) {
				if(!visited[i]) dfs(i, end, arr);
			}
		}
		arr.remove((Integer) cur);
		visited[cur] = false;
	}
	
	static void bfs() {
		for(int i: bunny) {
			if (escapePath.contains(i)) {
				ans = 0;
				return;
			}
		}
		
		Queue<Integer> que = new ArrayDeque<Integer>();
		boolean[] bunny_visited = new boolean[N+1];
		int[] dis = new int[N+1];
		
		for(int i: bunny) {
			if(!bunny_visited[i]) {
				que.add(i);
				bunny_visited[i]=true;
			}
		}
			
		while(!que.isEmpty()) {
			int a = que.poll();
			if(escapePath.contains(a)) {
				ans = dis[a];
				return;
			}
			
			for (int j: adj[a]) {
				if(!bunny_visited[j]) {
					que.add(j);
					bunny_visited[j]=true;
					dis[j]=dis[a]+1;
				}
			}
		}
	}
	
	
	static class FastReader {
	    BufferedReader br;
	    StringTokenizer st;

	    public FastReader()
	    {
	        br = new BufferedReader(
	            new InputStreamReader(System.in));
	    } 

	    String next()
	    {
	        while (st == null || !st.hasMoreElements()) {
	            try {
	                st = new StringTokenizer(br.readLine());
	            }
	            catch (IOException e) {
	                e.printStackTrace();
	            }
	        }
	        return st.nextToken();
	    }

	    int nextInt() { return Integer.parseInt(next()); }

	    long nextLong() { return Long.parseLong(next()); }

	    double nextDouble()
	    {
	        return Double.parseDouble(next());
	    }

	    String nextLine()
	    {
	        String str = "";
	        try {
	            if(st.hasMoreTokens()){
	                str = st.nextToken("\n");
	            }
	            else{
	                str = br.readLine();
	            }
	        }
	        catch (IOException e) {
	            e.printStackTrace();
	        }
	        return str;
	    }
	}
}