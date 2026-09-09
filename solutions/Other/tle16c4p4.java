import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	static int N, M, Q;
	static int far, pre[];
	static long dia, dis[];  
	static boolean vis[];
    static List<Pair> adj[];
    static int start;
    static Long mn, mx;
    
    public static void main(String[] args) throws IOException{
		try {
	    	N = readInt();
	    	M = readInt();
	    	Q = readInt();
	    	pre = new int[N+1]; dis=new long[N+1]; vis=new boolean[N+1];
	    	adj = new ArrayList[N+1];
	    	for(int i=1; i<=N; i++) adj[i] = new ArrayList<>();
	    	for(int i=0; i<M; i++) {
	    		int u = readInt(), v = readInt(), w = readInt();
	    		start = u;
	    		adj[u].add(new Pair(v, w));
	    		adj[v].add(new Pair(u, w));
	    	}
	    	
	    	if(M==0) {
	    		out.println(Q==1?N-1 : 1);
	    		return;
	    	}
	    	
	    	dfs(start, -1, 0); dia = 0; dfs(far, -1, 0);
	    	long rad = Long.MAX_VALUE;
	    	for(int u=far; u!= -1; u = pre[u]) {
	    		rad = Math.min(rad, Math.max(dis[u], dia - dis[u]));
	    	}
	    	mx=(long)dia; mn=(long)rad;
	    	
	    	for(int i=1; i<=N; i++) {
	    		if(vis[i]) continue;
	    		
	    		dia = 0; far=i;
	    		//no need to reset pre[] and dis[], as sub-trees have no overlap.
	    		//pre = new int[N+1]; dis=new int[N+1];
	    		dfs(i, -1, 0); dia = 0; dfs(far, -1, 0);
	    		rad = Long.MAX_VALUE;
		    	for(int u=far; u!= -1; u = pre[u]) {
		    		rad = Math.min(rad, Math.max(dis[u], dia - dis[u]));
		    	}
	    		
	    		mx += (dia + 1);
	    		if(mn==rad) mn++;
	    		else mn = Math.max(mn, rad);
	    	}
	    	out.println(Q==1?mx:mn);
			
		} finally {
			out.flush();
			out.close();
		}
    }

    static void dfs(int u, int par, long d) {
    	vis[u] = true;
    	pre[u] = par; dis[u] = d;
    	if(d > dia) { dia = d; far = u; }
    	if(adj[u].size()>0)
    	for(Pair e : adj[u]) {
    		if(e.x != par) dfs(e.x, u, d + e.y);
    	}
    }
	
	
	static class Pair implements Comparable<Pair> {
		int x, y;
		Pair(int x0, int y0) {
			x=x0;
			y=y0;
		}
		
		// Overriding equals() to compare two Pair objects
	    @Override
	    public boolean equals(Object o) {
	        if (o == this) return true;

	        if (!(o instanceof Pair)) return false;
	         
	        Pair p = (Pair) o;
	        return (Integer.compare(x, p.x)==0 && Integer.compare(y, p.y)==0);
	    }
	    
	    // Overriding toString() method of String class
	    @Override
	    public String toString() {
	        return "(" + this.x + ", " + this.y + ") ";
	    }
	    

		public int compareTo (Pair p) {
			int ret = Integer.compare(x, p.x);
			if (ret==0) {
				return Integer.compare(y, p.y);
			} else {
				return ret;
			}
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