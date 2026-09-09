import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	static int N;
	static long K;
	static int[][] adj = null;
	static ArrayList<Pair> arr = new ArrayList<Pair>();
	static int startLoop = 0;


	public static void main(String[] args) throws IOException {
		try {
			N = readInt();
			K = readLong();
			adj = new int[N+1][N+1];
			
			int a;
			for(int i=1; i<=N; i++) 
				for(int j=1; j<=N; j++) 
					adj[i][j] = readInt();
			
			
			nextShow(1, 2);
			
			//System.out.println(arr.size()+"; start="+startLoop);
			int leading = arr.size();
			int patterSize = leading - startLoop;
			int idx = 0;
			if(K<=leading) {
				idx = (int)K;
			} else {
				long d = K - startLoop;
				int r = (int) (d%patterSize);
				idx = startLoop + (r==0?patterSize : r);
			}
			Pair p = arr.get(idx-1);
			out.println(p.x);
			return; 
						
		} finally {
			out.flush();
			out.close();
		}
		
	}	//end of main()

	
	public static void nextShow(int a, int b) {
		Pair p = new Pair(a, b);
		if(arr.contains(p)) {
			//stop recursion when a loop is detected.
			startLoop = arr.indexOf(p);
			return;
		}
		else {
			arr.add(p);
			int c = adj[b][a];
			nextShow(b, c);
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