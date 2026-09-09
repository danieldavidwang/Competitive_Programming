import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.stream.Collectors;

public class Main {
	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	static int N;
	static ArrayList<Pair>[] adj = null;
	static int len, far;
	static int diameter, radius;
	static Stack<Pair> path = new Stack<Pair>();
	

	public static void main(String[] args) throws IOException {
		try {
			N = readInt();
			adj = new ArrayList[N+1];
			for(int i=1; i<=N; i++) {
				adj[i] = new ArrayList<Pair>();
			}
			
			for(int i=0; i<N-1; i++) {
				int u = readInt();
				int v = readInt();
				int w = readInt();
				adj[u].add(new Pair(v, w));
				adj[v].add(new Pair(u, w));
			}
			
			dfs(1, -1, 0, new Stack<Pair>()); len = 0; dfs(far, -1, 0, new Stack<Pair>());
			
			diameter = len;
			radius = Integer.MAX_VALUE;
			for(Pair p: path) {
				int s = Math.max(p.y, (diameter-p.y));
				if(radius>s) radius = s;
			}
			
			out.println(diameter);
			out.println(radius);
						
		} finally {
			out.flush();
			out.close();
		}
		
	}

	static void dfs(int cur, int pre, int dis, Stack<Pair> pt) {
		pt.push(new Pair(cur, dis));
		if(dis > len) {
			far = cur; len = dis;
			path.clear();
			path.addAll(pt);
		}
		for(Pair nxt : adj[cur]) {
			if(nxt.x != pre) dfs(nxt.x, cur, dis+nxt.y, pt);
		}
		pt.pop();
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