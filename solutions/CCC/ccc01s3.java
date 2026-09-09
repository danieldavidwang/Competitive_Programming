import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Stack;
import java.util.StringTokenizer;

public class MainStrategicBombing {

	static final int MAX = 26;
	static final char BASE = 'A';
	static String inp = null;
	static ArrayList<String> edges = new ArrayList();
	static int[][] map = new int[MAX][MAX];
	static int[] cnnt = new int[MAX];
	static int ans = 0;
	
	public static boolean dfs(String road) {
		Stack<Integer> stck = new Stack<Integer>();
		int[] visited = new int[MAX];
		int rs = road.charAt(0)-BASE;
		int re = road.charAt(1)-BASE;
		
		stck.push(0);
		
		while (!stck.isEmpty()) {
			int cur = stck.pop();
			
			if(visited[cur]!=0) continue;
			
			visited[cur]=1;
			for(int i=0; i<MAX; i++) {
				if(map[cur][i]==0) continue;
				
				if((cur==rs && i==re) || (cur==re && i==rs)) continue;

				if(i==1) {
					return false;
				}
				else {
					stck.push(i);
				}
			}
		}
		
		return true;
	}
	
	
	public static void main(String[] args) throws IOException {
		PrintWriter out=new PrintWriter(System.out);
		
		FastReader sr = new FastReader();
		
		inp = sr.next();
		while (!inp.equals("**")) {
			int s = inp.charAt(0)-BASE;
			int e = inp.charAt(1)-BASE;
			map[s][e] = 1;
			map[e][s] = 1;
			edges.add(inp);
			
			inp = sr.next();
		}
		
		for(int i=0; i<edges.size(); i++) {
			String road = edges.get(i);
			if(dfs(road)) {
				out.println(road);
				ans++;
			}
		}
		out.println("There are " + ans + " disconnecting roads.");
		
		out.flush();
		out.close();
		
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