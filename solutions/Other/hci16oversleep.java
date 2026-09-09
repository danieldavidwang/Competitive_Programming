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


//https://dmoj.ca/problem/hci16oversleep - Oversleep


public class MainOversleep {

	static PrintWriter out = new PrintWriter(System.out);
	static FastReader sr = new FastReader();

	static final int MAX = 1000;
	static final char START = 's';
	static final char END = 'e';
	static final char PATH = '.';
	static final char BLOCK = 'X';
	static final int[][] OFFSET = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	static int N=0, M=0;
	static char[][] inp = null;
	static int[][] visited = null;
	static int[][] distance = null;
	static int sx, sy;
	static int ex, ey;
	static int[] pair = new int[2];
	static Queue<int[]> que = new ArrayDeque<int[]>();
	
	public static void bfs() {
		
		pair[0] = sx; pair[1] = sy;
		que.add(pair);
		visited[sx][sy]=1;
		distance[sx][sy]=-1;
		
		while(!que.isEmpty()) {
			pair = que.poll();
			int px = pair[0];
			int py = pair[1];
			int d = distance[px][py];
			//System.out.println("---px="+px+"; py="+py);
			
			if(px==ex && py==ey) {
				return;
			} else {
				for(int i=0; i<4; i++) {
					int nx = px+OFFSET[i][0];
					int ny = py+OFFSET[i][1];
					if(nx==ex && ny==ey) {
						distance[nx][ny] = d+1;
						return;
					} else if(nx>=1 && nx<=N && ny>=1 && ny<=M && visited[nx][ny]==0 && inp[nx][ny]!='X') {
						que.add(new int[] {nx, ny});
						//System.out.println("nx="+nx+"; ny="+ny);
						visited[nx][ny]=1;
						distance[nx][ny]=d+1;
					}
				}
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		
		N = sr.nextInt();
		M = sr.nextInt();
		inp = new char[N+1][M+1];
		visited = new int[N+1][M+1];
		distance = new int[N+1][M+1];
		for(int i=1; i<=N; i++) {
			String str = sr.next();
			for(int j=1; j<=M; j++) {
				inp[i][j] = str.charAt(j-1);
				
				if(inp[i][j]=='s') {
					sx=i; sy=j;
				} else if(inp[i][j]=='e') {
					ex=i; ey=j;
				}
			}
		}
		distance[ex][ey] = -1;
		
		bfs();
		out.println(distance[ex][ey]);
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