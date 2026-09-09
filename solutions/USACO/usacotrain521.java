import java.io.*;
import java.util.*;


public class MainS3Trails_recursion {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int N, B;
	static boolean[][] bar;
	static boolean[][] vis;
	static int[][] con = new int[4][2];
	static int ans = 0;
	
	public static void main(String[] args) throws IOException {
		try {
			N = readInt(); B = readInt();
			bar = new boolean[N+1][N+1];
			for(int i=0; i<B; i++) {
				String str = next().toUpperCase();
				int x = Integer.parseInt(str.substring(1));
				int y = (str.charAt(0)-'A') + 1;
				if(!goout(x, y)) bar[x][y] = true;
			}
			
			con[0][0]=con[1][1]=-1;
			con[3][0]=con[2][1]=1;
			ans = 0;
			
			vis = new boolean[N+1][N+1];
			gonext(1, 1, 2, 1);
			
			vis = new boolean[N+1][N+1];
			gonext(1, 1, 3, 1);
			
			out.println(ans);
			
		} finally {
			out.flush();
			out.close();
		}
		
	}
	
	static boolean goout(int x, int y) {
		return (x<1 || x>N || y<1 || y>N);
	}
	
	static void gonext(int x, int y, int d, int step) {
		//out.println("x="+x+"; y="+y+"; d="+d+"; step="+step);
		if(vis[x][y]) return;
		
		vis[x][y] = true;
		ans = Math.max(ans, step);
		int xx = x+con[d][0]; 
		int yy = y+con[d][1];
		if(goout(xx, yy) || bar[xx][yy]) {
			if (d==0 || d==3) {
				xx = x+con[1][0]; yy=y+con[1][1];
				if(!goout(xx, yy) && !bar[xx][yy]) gonext(xx, yy, 1, step+1);
				xx = x+con[2][0]; yy=y+con[2][1];
				if(!goout(xx, yy) && !bar[xx][yy]) gonext(xx, yy, 2, step+1);
			} else {
				xx = x+con[0][0]; yy=y+con[0][1];
				if(!goout(xx, yy) && !bar[xx][yy]) gonext(xx, yy, 0, step+1);
				xx = x+con[3][0]; yy=y+con[3][1];
				if(!goout(xx, yy) && !bar[xx][yy]) gonext(xx, yy, 3, step+1);
			}
		} 
		else gonext(xx, yy, d, step+1);
		vis[x][y] = false;
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