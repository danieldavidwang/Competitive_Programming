import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Queue;
import java.util.StringTokenizer;

public class MainS3YearOfCow {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	
	static final Map<String, Integer> ZOD = new HashMap<String, Integer>() {{
	    put("Ox", 0);
	    put("Tiger", 1);
	    put("Rabbit", 2);
	    put("Dragon", 3);
	    put("Snake", 4);
	    put("Horse", 5);
	    put("Goat", 6);
	    put("Monkey", 7);
	    put("Rooster", 8);
	    put("Dog", 9);
	    put("Pig", 10);
	    put("Rat", 11);
	}};
	 
	 
	static int N=0;
	static ArrayList<Integer>[] adj;
	static ArrayList<String> names = new ArrayList<String>();
	static int[] indegree;
	static boolean[] signs;
	static int[] animals;
	static int[] ans;

	public static void main(String[] args) throws IOException {
		try {
			N = readInt();
			adj = new ArrayList[N+1];
			indegree = new int[N+1];
			signs = new boolean[N+1];
			animals = new int[N+1];
			ans = new int[N+1];
			
			names.add("Bessie");
			indegree[0]=0;
			signs[0] = true;
			animals[0] = 0;
			ans[0] = 0;
			
			
			for(int i=0; i<N+1; i++) adj[i] = new ArrayList<Integer>();
			for(int i=1; i<=N; i++) {
				String s1 = next();
				String s2 = next();
				String s3 = next();
				String s4 = next();
				String s5 = next();
				String s6 = next();
				String s7 = next();
				String s8 = next();
				
				names.add(s1);
				signs[i] = (s4.equals("previous"))? true:false;
				animals[i] = ZOD.get(s5);
				
				int u = names.indexOf(s8);
				adj[u].add(i);
				indegree[i]++;
			}

			topsort();
			out.println(Math.abs(ans[names.indexOf("Elsie")]));
			
		} finally {
			out.flush();
			out.close();
		}
		
	}	//end of main()
	
	static void topsort() {
		Queue<Integer> que = new ArrayDeque<Integer>();
		int cnt = 0;
		for(int i=0; i<N+1; i++)
			if(indegree[i] == 0) que.add(i);
		
		while(!que.isEmpty()) {
			int u = que.poll();
			for(int v: adj[u]) {
				if((--indegree[v]) == 0) que.add(v);
				
				int dif = animals[v]-animals[u];
				if(signs[v]) {
					if(dif>=0) ans[v] = ans[u] + (dif-12);
					else ans[v] = ans[u] + dif;
				}
				else {
					if(dif>0) ans[v] = ans[u] + dif;
					else ans[v] = ans[u] + (dif + 12);
				}
			}
			
		}
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