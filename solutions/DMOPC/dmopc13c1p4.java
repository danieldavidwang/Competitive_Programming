import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Map;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class MainAFK {
	static PrintWriter out = new PrintWriter(System.out);
	static FastReader sr = new FastReader();

	static final int MAX = 5000;
	static final int MAX_STEPS = 60;
	static final String NOT_WORTH= "#notworth";
	static final char START = 'C';
	static final char END = 'W';
	static final char PATH = 'O';
	static final char BLOCK = 'X';
	static final int[][] OFFSET = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	static int T=0, L=0, W=0;
	static char[][] inp = null;
	static int[][] visited = null;
	static int[][] distance = null;
	static int sx=-1, sy=-1;
	static int ex=-1, ey=-1;
	static int[] pair = new int[2];
	static Queue<int[]> que = new ArrayDeque<int[]>();
	
	public static void bfs() {
		// remember to clear Queue as this program run many test cases!!!!!!!!!!!!
		que.clear();
		pair[0] = sx; pair[1] = sy;
		que.add(pair);
		visited[sx][sy]=1;
		distance[sx][sy]=0;
		
		while(!que.isEmpty()) {
			pair = que.poll();
			int px = pair[0];
			int py = pair[1];
			int d = distance[px][py];
			
			if(px==ex && py==ey) {
				return;
			} else {
				for(int i=0; i<OFFSET.length; i++) {
					int nx = px+OFFSET[i][0];
					int ny = py+OFFSET[i][1];
					if(nx>=0 && nx<L && ny>=0 && ny<W && visited[nx][ny]==0 && inp[nx][ny]!=BLOCK) {
						if(nx==ex && ny==ey) {
							distance[nx][ny] = d+1;
							return;
						}
						que.add(new int[] {nx, ny});
						visited[nx][ny]=1;
						distance[nx][ny]=d+1;
					}
				}
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		T = sr.nextInt();
		for(int k=0; k<T; k++) {
			W = sr.nextInt();
			L = sr.nextInt();

			inp = new char[L][W];
			visited = new int[L][W];
			distance = new int[L][W];

			for(int i=0; i<L; i++) {
				String str = sr.next();
				
				for(int j=0; j<W; j++) {
					inp[i][j] = str.charAt(j);
					if(inp[i][j]==START) {
						sx=i; sy=j;
					} 
					if(inp[i][j]==END) {
						ex=i; ey=j;
					}
				}
			}
			distance[ex][ey] = 100; //use any number bigger than 60.
			
			bfs();
			if(distance[ex][ey]<MAX_STEPS) {
				out.println(distance[ex][ey]);
			} else {
				out.println(NOT_WORTH);
			}
			
		}
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