import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Iterator;
import java.util.StringTokenizer;

//https://dmoj.ca/problem/graph3p1 - Travelling Salesmen
public class Main {
	static PrintWriter out = new PrintWriter(System.out);
	static FastReader sr = new FastReader();

	static final int MAX = 100000;
	static int N=0, M=0, K=0;
	static ArrayList<Integer>[] edges = null;
	static int[] offices = null;
	static ArrayList<Integer> arr = new ArrayList<Integer>();
	static ArrayList<Integer> cur1 = new ArrayList<Integer>();
	static ArrayList<Integer> cur2 = new ArrayList<Integer>();
	
	public static void main(String[] args) throws IOException {
		try {
			N = sr.nextInt();
			M = sr.nextInt();
			edges = new ArrayList[N+1];
			for(int i=1; i<=N; i++) {
				arr.add(i);
				edges[i] = new ArrayList<Integer>();
			}
			
			for(int i=0; i<M; i++) {
				int a = sr.nextInt();
				int b = sr.nextInt();
				edges[a].add(b);
				edges[b].add(a);
			}
			
			K = sr.nextInt();
			offices = new int[K];
			for(int i=0; i<K; i++) {
				int ofc = sr.nextInt();
				offices[i] = ofc;
				
				cur1.add(ofc);
				arr.remove((Integer) ofc);
			}
			
			int cnt = 0;
			while(arr.size()>0) {
				cnt++;
				
				for(int i=0; i<cur1.size(); i++) {
					int cc = cur1.get(i);
					for(int j=0; j<edges[cc].size(); j++) {
						int nc = edges[cc].get(j);
						if(arr.contains(nc)) {
							cur2.add(nc);
							arr.remove((Integer) nc);
						}
					}
				}
				cur1 = new ArrayList<Integer>();
				cur1.addAll(cur2);
				cur2 = new ArrayList<Integer>();
			}
			
			out.println(cnt);
		} finally {
			out.flush();
			out.close();
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