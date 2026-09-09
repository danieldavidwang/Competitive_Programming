import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Queue;
import java.util.StringTokenizer;

//https://dmoj.ca/problem/tsoc15c1p5 - TSOC '15 Contest 1 #5 - Giant Ants
public class Main {

	static PrintWriter out = new PrintWriter(System.out);
	static FastReader sr = new FastReader();

	static int N=0, M=0, W=0;
	static int[][] adj = null;
	static int[] ant = null;
	
	public static void main(String[] args) throws IOException {
		try {
			N = sr.nextInt();
			M = sr.nextInt();
			adj = new int[N+1][N+1];
			ant = new int[N+1];
			Arrays.fill(ant, 4*N+10); 
			
			for(int i=0; i<M; i++) {
				int a = sr.nextInt();
				int b = sr.nextInt();
				adj[a][b]=1;
				adj[b][a]=1;
			}
			
			W = sr.nextInt();
			for(int i=0; i<W; i++) {
				int a = sr.nextInt();
				ant[a]=0;
			}
			
			bfsAnt();
			int ret = bfs();
			if(ret == -1) out.println("sacrifice bobhob314");
			else out.println(ret);
			
		} finally {
			out.flush();
			out.close();
		}
	}
	
	public static void bfsAnt() {
		Queue<Integer> que = new ArrayDeque<Integer>();
		int[] ant_visited = new int[N+1];
		
		for(int i=1; i<=N; i++) {
			if(ant[i]==0) {
				que.add(i);
				ant_visited[i]=1;
				ant[i]=0;
			}
		}
			
		while(!que.isEmpty()) {
			int a = que.poll();
			
			for(int j=1; j<=N; j++) {
				if(adj[a][j]==1 && ant_visited[j]==0) {
					que.add(j);
					ant_visited[j]=1;
					ant[j]=ant[a]+1*4;
				}
			}
		}
	}
	
	public static int bfs() {

		Queue<Integer> que = new ArrayDeque<Integer>();
		int[] visited = new int[N+1];
		int[] distance = new int[N+1];
		
		que.add(1);
		visited[1]=1;
		distance[1]=0;
		
		while(!que.isEmpty()) {
			int a = que.poll();
			if(a==N) return distance[a];
			
			for(int i=1; i<=N; i++) {
				if(adj[a][i]==1 && visited[i]==0 && (distance[a]+1)<=ant[i]) {
					que.add(i);
					visited[i]=1;
					distance[i]=distance[a]+1;
				}
			}
		}
		return -1;
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