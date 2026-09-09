import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Queue;
import java.util.StringTokenizer;

public class MainCatchCat_bfs {

	static PrintWriter out = new PrintWriter(System.out);
	static FastReader sr = new FastReader();
	
	static final int MAX = 100001;
	static int X = 0, Y = 0;
	static int curX = 0;
	static int[] visited = new int[MAX*2];
	static int[] depth = new int[MAX*2];
	static int shortest = 0;
	
	public static void goNext(int nt, Queue<Integer> que) {
		if(nt>=0 && nt<MAX && visited[nt]==0) {
			que.add(nt);
			visited[nt]=1;
			depth[nt] = depth[curX]+1;
		}
	}
	
	public static void isTree() {
		
		Queue<Integer> que = new ArrayDeque<Integer>();
		que.add(X);
		visited[X]=1;
		depth[X]=0;
		
		while(!que.isEmpty()) {
			curX = que.poll();
			//out.println("curX="+curX+"; depth="+depth[curX]);
			
			if(curX==Y) {
				shortest = depth[curX];
				return;
			} else {
				int c1 = curX+1;
				int c2 = curX-1;
				int c3 = curX*2;
				goNext(curX+1, que);
				goNext(curX-1, que);
				goNext(curX*2, que);
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		
		X = sr.nextInt();
		Y = sr.nextInt();
		shortest = 0;
		
		isTree();
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