import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Queue;
import java.util.StringTokenizer;

//https://dmoj.ca/problem/tsoc16c1p4 - Alex and Animal Rights
public class Main {

	static PrintWriter out = new PrintWriter(System.out);
	static FastReader sr = new FastReader();

	static final int MAX_R = 35;
	static final int MAX_C = 50;
	static final char EMPTY = '.';
	static final char WALL = '#';
	static final char MONKEY = 'M';
	static final int[][] OFFSET = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	static int R=0, C=0;
	static char[][] inp = null;
	static int[][] visited = null;
	//static ArrayList<Integer> rooms=new ArrayList<Integer>();
	static Queue<Pair> que = new ArrayDeque<Pair>();
	static Pair pair = null;
	static int ans = 0;
	

	public static void main(String[] args) throws IOException {
		
		try {
			R = sr.nextInt();
			C = sr.nextInt();

			inp = new char[R][C];
			visited = new int[R][C];
			for(int i=0; i<R; i++) {
				String str = sr.next();
				for(int j=0; j<C; j++) inp[i][j] = str.charAt(j);
			}
			
			for(int i=0; i<R; i++) {
				for(int j=0; j<C; j++) {
					if(inp[i][j]!=WALL  && visited[i][j] == 0) {
						bfs(i, j);
					}
				}
			}
			
			out.println(ans);
			
		} finally {
			out.flush();
			out.close();
		}
		
		
	}	//end of main()
	
	
	public static void bfs(int x, int y) {
		que.clear();
		que.add(new Pair(x, y));
		visited[x][y]=1;
		boolean containM = false;
		
		while(!que.isEmpty()) {
			pair = que.poll();
			int px = pair.x;
			int py = pair.y;
			if(inp[px][py]==MONKEY) containM = true;
			for(int i=0; i<OFFSET.length; i++) {
				int nx = px+OFFSET[i][0];
				int ny = py+OFFSET[i][1];
				if(nx>=0 && nx<R && ny>=0 && ny<C && visited[nx][ny]==0) {
					visited[nx][ny]=1;
					if(inp[nx][ny]!=WALL) que.add(new Pair(nx, ny));
				}
			}
		}
		
		if(containM) ans++;
	}
	

	static class Pair {
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