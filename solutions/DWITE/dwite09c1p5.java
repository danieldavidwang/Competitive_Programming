import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.StringTokenizer;


public class Main {

	static PrintWriter out = new PrintWriter(System.out);
	static FastReader sr = new FastReader();

	static final int TS = 5;	
	static final int MAX = 101;
	static int N;
	static int[][] adj = null;
	static int[] visited = null;
	static HashMap<Integer, Integer> stk = null; 
	static int label, circlesize;

	public static void main(String[] args) throws IOException {
		try {
			for(int t=0; t<TS; t++) {
				label = 0; circlesize=0;
				adj = new int[MAX][MAX];
				visited = new int[MAX];
				stk = new HashMap();
				
				N = sr.nextInt();
				for(int i=0; i<N; i++) {
					int u = sr.nextInt();
					int v = sr.nextInt();
					adj[u][v]=1;
				}
				
				for(int i=1; i<=MAX; i++) {
					if(visited[i]==0) {
						dfs(i, 0);
						if(circlesize>0) {
							out.println(circlesize);
							break;
						}
					}
				}
			}
			
		} finally {
			out.flush();
			out.close();
		}
	}
	
	static void dfs(int cur, int pre) {
		visited[cur] = visited[pre]+1;
		stk.put(cur, visited[cur]);

		if(circlesize==0) {
			for(int i=1; i<MAX; i++) {
				if(adj[cur][i]==1) {
					if(visited[i]==0) {
						visited[cur] = visited[pre]+1;
						dfs(i, cur);
					}
					else if(stk.containsKey(i)) {
						circlesize = visited[cur]-visited[i]+1;
					}
				}
			}
		}
		
		stk.remove(cur);
	}


	static class Pair {
		int x, y;
		Pair(int x0, int y0) {
			x=x0;
			y=y0;
		}
		
	    @Override
	    public boolean equals(Object o) {
	        if (o == this) return true;

	        if (!(o instanceof Pair)) return false;
	         
	        Pair p = (Pair) o;
	        return (Integer.compare(x, p.x)==0 && Integer.compare(y, p.y)==0);
	    }
	    
	    @Override
	    public String toString() {
	        return "(" + this.x + ", " + this.y + ") ";
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