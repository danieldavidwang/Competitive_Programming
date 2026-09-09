import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class MainS3AnimeConventions {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	static final String AQ = "A", QQ = "Q", YES = "Y", NO = "N";
	static int N, Q;
	static UnionFind uf;
	static double ans;
	
    
    public static void main(String[] args) throws IOException{
		try {
	    	N = readInt();
	    	Q = readInt();
	    	uf = new UnionFind(N+1);
	    	for(int i=0; i<Q; i++) {
	    		String action = next();
	    		int x = readInt();
	    		int y = readInt();
	    		if(action.equals(AQ)) {
	    			if(uf.find(x)!=uf.find(y)) uf.union(x, y);
	    		} else {
	    			if(uf.find(x)==uf.find(y)) out.println(YES);
	    			else out.println(NO);
	    		}
	    	}
			
		} finally {
			out.flush();
			out.close();
		}
    }
    
    
    static class UnionFind {
        int[] parent;
        UnionFind(int n) {
            parent = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
     
        public int find(int x) {
            if (x == parent[x]) {
                return x;
            }
            return parent[x] = find(parent[x]);
        }
     
        public void union(int x, int y)  {
            int px = find(x);
            int py = find(y);
            if (px != py) {
                parent[px] = py;
            }
        }
     
        public int size() {
            int ans = 0;
            for (int i = 0; i < parent.length; ++ i) {
                if (i == parent[i]) ans ++;
            }
            return ans;
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