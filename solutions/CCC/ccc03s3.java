import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Queue;
import java.util.StringTokenizer;

public class MainS3FloorPlan {

	static PrintWriter out = new PrintWriter(System.out);
	static FastReader sr = new FastReader();

	static final int MAX = 64;
	static final char PATH = '.';
	static final char BLOCK = 'I';
	static final int[][] OFFSET = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	static int F=0, R=0, C=0;
	static char[][] inp = null;
	static int[][] visited = null;
	//static int[][] distance = null;
	static int[] pair = new int[2];
	static Queue<int[]> que = new ArrayDeque<int[]>();
	static ArrayList<Integer> rooms=new ArrayList<Integer>();
	
	public static void bfs(int x, int y) {
		que.clear();
		pair[0] = x; pair[1] = y;
		que.add(pair);
		visited[x][y]=1;
		int fls = 0;
		
		while(!que.isEmpty()) {
			pair = que.poll();
			int px = pair[0];
			int py = pair[1];
			fls++;
			for(int i=0; i<OFFSET.length; i++) {
				int nx = px+OFFSET[i][0];
				int ny = py+OFFSET[i][1];
				if(nx>=0 && nx<R && ny>=0 && ny<C && visited[nx][ny]==0) {
					visited[nx][ny]=1;
					if(inp[nx][ny]==PATH) que.add(new int[] {nx, ny});
				}
			}
		}
		
		rooms.add(fls);
		//System.out.println(Arrays.toString(rooms.toArray()));
	}
	
	public static void main(String[] args) throws IOException {
		
		F = sr.nextInt();
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
				if(inp[i][j]==PATH  && visited[i][j] == 0) {
					bfs(i, j);
				}
			}
		}
		
		Collections.sort(rooms);
		int cnt=0, left=F;
		for(int i=rooms.size(); i>0; i--) {
			int chk = left-rooms.get(i-1);
			if(chk>=0) {
				left = chk;
				cnt++;
			} else break;
		}
		
		String cntrm = (cnt==1)? cnt+" room, " : cnt+" rooms, ";
		out.println(cntrm + left + " square metre(s) left over");
		
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