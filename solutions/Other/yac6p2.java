import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class MainCompYet_Q2_BFS_HashSet {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	static int N;
	static ArrayList<Integer> adj[] = null;
	static int s[];
	static boolean[] vis = null;
	static ArrayList<int[]> ans = new ArrayList<int[]>();
	
	public static void main(String[] args) throws IOException{
		try {

	    	N = readInt();
	    	s = new int[N+1];
	    	adj = new ArrayList[N+1];
	    	vis = new boolean[N+1];
	    	int b1=0, b2=0;
	    	
	    	for(int i=0; i<=N; i++)  adj[i] = new ArrayList<Integer>();
	    	
	    	for(int i=1; i<=N; i++) {
	    		int a = readInt();
	    		s[i] = a;
	    		if(a==-1) {
	    			s[i] = i;
	    			b1=i;
	    		}
	    	}
	    	for(int i=1; i<=N; i++) {
	    		int a = readInt();
	    		if(a==-1) {
	    			adj[0].add(i);
	    			b2=i;
	    		} else {
	    			adj[a].add(i);
	    		}
	    	}
	    	if(b1 != b2) {
	    		out.println(-1);
	    		return;
	    	}
	    	
	    	bfs(b1);
	    	out.println(ans.size());
			for (int[] a : ans) out.println(a[0]+" "+a[1]);
			
		} finally {
			out.flush();
			out.close();
		}
    }
	
	
	public static void bfs(int start) {
		Queue<Integer> que = new ArrayDeque<Integer>();
		que.add(start);
		vis[start]=true;
		
		while(!que.isEmpty()) {
			int a = que.poll();
			
			for(int i: adj[a]) {
				if(!vis[i]) {
					if(s[i]!=a) {
						//boss is changed, reorg...
						int[] mv = new int[2];
						mv[0] = i;
						mv[1] = a;
						ans.add(mv);
					}
					que.add(i);
					vis[i]=true;
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