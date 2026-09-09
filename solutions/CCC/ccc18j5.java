import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Queue;
import java.util.StringTokenizer;

public class MainCYOP {
	static PrintWriter out = new PrintWriter(System.out);
	static FastReader sr = new FastReader();
	
	
	static String YES = "Y";
	static String NO = "N";
	static final int MAX = 10000;
	static int N = 0, M = 0;
	static int[] visited = null;
	static int[] depth = null;
	//static int[][] edges = null;
	static HashSet<Integer>[] edges = null;
	static int shortest = 0;
	
	public static String isTree() {
		
		Queue<Integer> que = new ArrayDeque<Integer>();
		que.add(1);
		visited[1]=1;
		depth[1]=1;
		
		while(!que.isEmpty()) {
			int cur = que.poll();
			
			if(edges[cur].size()==0) {
				if(shortest==0) shortest = depth[cur];
			} else {
				Iterator<Integer> it = edges[cur].iterator();
				while (it.hasNext()) {
					int p = it.next();
					if(visited[p]==0) {
						que.add(p);
						visited[p]++;
						depth[p] = depth[cur]+1;
					}
				}
			}
		}
		
		for(int i=1; i<=N; i++) {
			if(visited[i]==0) {
				return NO;
			}
		}
		
		return YES;
	}
	
	public static void main(String[] args) throws IOException {
		
		N = sr.nextInt();
		visited = new int[N+1];
		depth  = new int[N+1];
		//edges = new int[N+1][N+1];
		edges = new HashSet[N+1];
		
		for(int i=1; i<=N; i++) {
			edges[i] = new HashSet<Integer>();
			M = sr.nextInt();
			for(int j=1; j<=M; j++) {
				int np = sr.nextInt();
				edges[i].add(np);
			}
		}
		

		
		String l1 = isTree();
		
		out.println(l1);
		out.println(shortest);
		
		out.flush();
		out.close();
		
	}	//end of main()

	
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