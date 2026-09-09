import java.io.*;
import java.util.*;

public class RoadNetwork {
	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    
    public static void main(String[] args) throws IOException{
        int n = readInt(), m = readInt(), x[] = new int[n+1], y[] = new int[n+1];
        List<Edge> adj[] = new ArrayList[n+1];
        for(int i=1; i<=n; i++) {
        	adj[i] = new ArrayList<>();
        	x[i] = readInt(); y[i] = readInt();
        	for(int j=1; j<i; j++) {
        		double d = Math.sqrt(Math.pow(x[i]-x[j], 2) + Math.pow(y[i]-y[j], 2));
        		adj[i].add(new Edge(j, d));
        		adj[j].add(new Edge(i, d));
        	}
        }
        for(int i=1; i<=m; i++) {
        	int u = readInt(), v = readInt();
        	adj[u].add(new Edge(v, 0));
        	adj[v].add(new Edge(u, 0));
        }
        
        double dis[] = new double[n+1];
        boolean vis[] = new boolean[n+1];
        Arrays.fill(dis,  1e18);
        dis[1] = 0.0;
        PriorityQueue<Edge> q = new PriorityQueue<>();
        q.add(new Edge(1, 0.0));
        while(!q.isEmpty()) {
        	int u = q.poll().v;
        	if(vis[u]) continue;
        	vis[u] = true;
        	for(Edge e: adj[u]) {
        		int v = e.v; double w = e.w;
        		if(!vis[v] && dis[v] > w) {
        			dis[v] = w; q.add(new Edge(v, dis[v]));
        		}
        	}
        }
        double sum = 0;
        for(int i=1; i<=n; i++) sum += dis[i];
        out.printf("%.2f\n", sum);
        
        out.flush();
		out.close();
    }
    
    static class Edge implements Comparable<Edge> {
    	int v;
    	double w;
    	Edge(int v0, double w0) {
    		v = v0; w = w0;
    	}
    	public int compareTo(Edge x) {
    		return Double.compare(w, x.w);
    	}
    	public String toString() {
    		return "v="+v+"; w="+w;
    	}
    }
    

    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
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
    static char readCharacter () throws IOException {
        return next().charAt(0);
    }
    static String readLine () throws IOException {
        return br.readLine().trim();
    }

}