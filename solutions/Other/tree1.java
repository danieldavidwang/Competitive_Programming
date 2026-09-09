import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Queue;
import java.util.StringTokenizer;

public class MainS3IsTree_final_FullScore_Queue {

	static FastReader sr = new FastReader();
	
	static String YES = "Yes";
	static String NO = "No";
	static final int MAX = 4;
	static int[][] matrix = new int[MAX][MAX];
	
	public static String isTree() {
		int[] visited = new int[MAX];
		int[][] edges = new int[MAX][MAX];
		
		Queue<Integer> que = new ArrayDeque<Integer>();
		que.add(0);
		visited[0]=1;
		
		while(!que.isEmpty()) {
			int cur = que.poll();
			for(int i=0; i<MAX; i++) {
				if(i==cur) continue;
				if(edges[cur][i]==1) continue;
				if(matrix[cur][i]==1) {
					que.add(i);
					visited[i]++;
					edges[cur][i]=1;
					edges[i][cur]=1;
				}
			}
		}
		
		for(int i=0; i<MAX; i++) {
			if(visited[i]!=1) {
				return NO;
			}
		}
		return YES;
	}
	
	public static void main(String[] args) throws IOException {
		for(int i=0; i<MAX; i++) {
			for(int j=0; j<MAX; j++) {
				matrix[i][j] = sr.nextInt();
			}
		}
		
		System.out.println(isTree());
		
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