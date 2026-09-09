import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Queue;
import java.util.StringTokenizer;

public class MainWand {

	static PrintWriter out=new PrintWriter(System.out);
	static FastReader sr = new FastReader();
	
	static int N, M;
	static HashMap<Integer, ArrayList<Integer>> loseing_map = null;
	static int[] visited = null;
	static int[] ans = null;
	
	public static void main(String[] args) throws IOException {
		
		N = sr.nextInt();
		M = sr.nextInt();
		loseing_map = new HashMap<Integer, ArrayList<Integer>>();
		ans = new int[N+1];
		visited = new int[N+1];
		
		for(int i=0; i<M; i++) {
			int winner = sr.nextInt();
			int loser = sr.nextInt();
			if(loseing_map.containsKey(loser)) {
				ArrayList<Integer> winnerList = loseing_map.get(loser);
				winnerList.add(winner);
				loseing_map.put(loser, winnerList);
			} else {
				loseing_map.put(loser, new ArrayList<Integer>(Arrays.asList(winner)));
			}
			
		}

		predictResult();
        
		for(int i=1; i<=N; i++) {
			out.print(ans[i]);
		}
		out.println();
		
		out.flush();
		out.close();
	}	
	
	public static void predictResult() {
		ArrayList<Integer> wand_winners = loseing_map.get(1);
		if(wand_winners==null || wand_winners.size()==0) {
			ans[1] = 1;
			return;
		}
		
		Queue<Integer> que = new ArrayDeque<>();
		que.add(1);

		while(!que.isEmpty()) {
			int cur_loser = que.poll();
			if (visited[cur_loser]>0) continue;
			visited[cur_loser] = 1;
			
			ArrayList<Integer> winners = loseing_map.get(cur_loser);
			if(winners==null || winners.size()==0) continue;
			for (int i=0; i<winners.size(); i++) {
				int winner = winners.get(i);
				if(ans[winner]==0) que.add(winner);
				ans[winner] = 1;
			}
		}
			
	}
	
	static class FastReader {
	    BufferedReader br;
	    StringTokenizer st;

	    public FastReader() {
	        br = new BufferedReader(
	            new InputStreamReader(System.in));
	    } 

	    String next() {
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

	    double nextDouble() {
	        return Double.parseDouble(next());
	    }

	    String nextLine() {
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