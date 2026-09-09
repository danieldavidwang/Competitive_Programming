import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.StringTokenizer;


public class MainS3ComfortableCows {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	
	static int N=0;
	static HashSet<String> arr = new HashSet<String>();
	static int matrix[][] = new int[1001][1001];
	static int ans[];
	
	
	public static void main(String[] args) throws IOException {
		try {
			N = readInt();
			ans = new int[N];
			
			for(int i=0; i<N; i++) {
				int x = readInt();
				int y = readInt();
				arr.add(x+","+y);
				int cnt = 0; int diff = 0;
				if(arr.contains((x-1)+","+y)) {
					cnt++; matrix[x-1][y]++;
					if(matrix[x-1][y]==3) diff++;
					else if(matrix[x-1][y]>3) diff--;
				}
				if(arr.contains((x+1)+","+y)) {
					cnt++; matrix[x+1][y]++;
					if(matrix[x+1][y]==3) diff++;
					else if(matrix[x+1][y]>3) diff--;
				}
				if(arr.contains(x+","+(y-1))) {
					cnt++; matrix[x][y-1]++;
					if(matrix[x][y-1]==3) diff++;
					else if(matrix[x][y-1]>3) diff--;
				}
				if(arr.contains(x+","+(y+1))) {
					cnt++; matrix[x][y+1]++;
					if(matrix[x][y+1]==3) diff++;
					else if(matrix[x][y+1]>3) diff--;
				}
				matrix[x][y] = cnt;
				if(matrix[x][y]==3) diff++;
				
				if(i<3) continue;
				ans[i] = ans[i-1]+diff;
				
			}
			StringBuilder str = new StringBuilder();
			for(int i=0; i<N; i++) str.append(ans[i]).append("\n");
			out.println(str);
			
		} finally {
			out.flush();
			out.close();
		}
		
	}	//end of main()
	
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