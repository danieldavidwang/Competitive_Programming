import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;


public class MainCompQ3_NewComponents_v11 {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	
	static int N, Q;
	static int[] par;
	static int[] chd;
	static boolean[] vis;
	static HashSet<Integer> S;
	static int[] c;
	static ArrayList<Integer> t1 = new ArrayList<Integer>();
	static ArrayList<Integer> t2 = new ArrayList<Integer>();
	static StringBuilder ans = new StringBuilder();
	
    
    public static void main(String[] args) throws IOException{
		try {
	    	N = readInt();
	    	Q = readInt();
	    	par = new int[N+1];
	    	chd = new int[N+1];
	    	vis = new boolean[N+1];
	    	c = new int[N+1];
	    	
    		
	    	for(int i=1; i<=N; i++) {
	    		int a = readInt();
	    		chd[i] = a;
	    		par[a] = i;
	    	}
	    	int cnt = 0;
	    	int cycle_index = 0;
	    	t1.add(0);
	    	for(int x=1; x<=N; x++) {
    			if(vis[x]) continue;
    			
    			int t = x;
    			while (!vis[t]) {
    				vis[t]  = true;
    	    		cnt++;
    				c[t] = cycle_index;
    	    		t = chd[t];
    	    	}
    			
    			t1.set(cycle_index, cnt);
				cycle_index++; cnt=0;
				t1.add(0);
			}
	    	t1.remove(t1.size()-1);
	    	
	    	
	    	if(t1.size()==1) {
	    		// one big cycle
	    		for(int i=0; i<Q; i++) {
		    	    S = new HashSet<Integer>();
		    	    for(int j=readInt(); j>0; j--) S.add(readInt());
		    	    
		    	    int eCnt = S.size();
		    	    for(int j : S) {
	    				if(S.contains(par[j])) eCnt--;
	    			}
		    		ans.append(eCnt).append("\n");
		    	}
	    	} else {
	    		for(int i=0; i<Q; i++) {
	    			S = new HashSet<Integer>();
		    	    for(int j=readInt(); j>0; j--) S.add(readInt());
	    			int ret = t1.size();
	    			int eCnt = S.size();
	    			HashSet<Integer> cycCnt = new HashSet<Integer>();
	    			for(int j : S) {
	    				cycCnt.add(c[j]);
	    				if(S.contains(par[j])) eCnt--;
	    			}
	    			ret += (eCnt-cycCnt.size());
		    		ans.append(ret).append("\n");
		    	}
	    	}
	    	
    		
	    	out.println(ans);
			
		} finally {
			out.flush();
			out.close();
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