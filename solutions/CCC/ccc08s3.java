import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

//https://dmoj.ca/problem/ccc08s3 - CCC '08 S3 - Maze
public class Main {
	static PrintWriter out = new PrintWriter(System.out);
	static FastReader sr = new FastReader();

	static final int MAX = 20;
	static final char ALL = '+';
	static final char H = '-';
	static final char V = '|';
	static final char BLOCK = '*';
	static final int[][] OFFSET_ALL = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	static final int[][] OFFSET_H = {{0, -1}, {0, 1}};
	static final int[][] OFFSET_V = {{-1, 0}, {1, 0}};
	
	static int T=0, R=0, C=0;
	static char[][] inp = null;
	static int[][] visited = null;
	static int[][] distance = null;
	static Queue<Pair> que = new ArrayDeque<Pair>();
	static Pair pair = null;
	
	public static void main(String[] args) throws IOException {
		try {
			T = sr.nextInt();
			for(int k=0; k<T; k++) {
				R = sr.nextInt();
				C = sr.nextInt();

				inp = new char[R][C];
				visited = new int[R][C];
				distance = new int[R][C];

				for(int i=0; i<R; i++) {
					String str = sr.next();
					for(int j=0; j<C; j++) {
						inp[i][j] = str.charAt(j);
					}
				}
				
				bfs();
				if(distance[R-1][C-1]>0) {
					out.println(distance[R-1][C-1]);
				} else {
					out.println(-1);
				}
			}
		} finally {
			out.flush();
			out.close();
		}
	}	
	
	public static void bfs() {
		que.clear();
		que.add(new Pair(0, 0));
		visited[0][0]=1;
		distance[0][0]=1;
		
		while(!que.isEmpty()) {
			pair = que.poll();
			int d = distance[pair.x][pair.y];
			char intersection = inp[pair.x][pair.y];
			int[][] offset = null;
			
			if(pair.x==R-1 && pair.y==C-1) {
				return;
			} else {
				switch(intersection) {
				  case ALL:
					  offset = OFFSET_ALL;
					  break;
				  case H:
					  offset = OFFSET_H;
					  break;
				  case V:
					  offset = OFFSET_V;
					  break;
				}
				for(int i=0; i<offset.length; i++) {
					int nx = pair.x+offset[i][0];
					int ny = pair.y+offset[i][1];
					if(nx>=0 && nx<R && ny>=0 && ny<C && visited[nx][ny]==0 && inp[nx][ny]!=BLOCK) {
						if(nx==(R-1) && ny==(C-1)) {
							distance[R-1][C-1] = d+1;
							return;
						}
						que.add(new Pair(nx, ny));
						visited[nx][ny]=1;
						distance[nx][ny]=d+1;
					}
				}
			}
		}
	}

	static class Pair {
		int x, y;
		Pair(int x0, int y0) {
			x=x0;
			y=y0;
		}
	    @Override
	    public boolean equals(Object o) {
	        if (o == this) {
	            return true;
	        }
	 
	        if (!(o instanceof Pair)) {
	            return false;
	        }
	         
	        Pair p = (Pair) o;
	         
	        return Integer.compare(x, p.x) == 0 && Integer.compare(y, p.y) == 0;
	    }	    
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