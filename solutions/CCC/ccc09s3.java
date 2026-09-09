import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Queue;
import java.util.StringTokenizer;

public class MainS3DegreeOfSeparation {

	static PrintWriter out = new PrintWriter(System.out);
	static FastReader sr = new FastReader();
	
	static String NOCON = "Not connected";
	static final int MAX = 50;
	static int[][] map = new int[MAX][MAX];
	
	public static void initMap() {
		map[1][6]=1;
		map[6][1]=1;
		
		map[2][6]=1;
		map[6][2]=1;
		
		map[3][6]=1;
		map[6][3]=1;
		
		map[3][4]=1;
		map[4][3]=1;
		
		map[3][5]=1;
		map[5][3]=1;
		
		map[3][15]=1;
		map[15][3]=1;
		
		map[4][6]=1;
		map[6][4]=1;
		
		map[5][6]=1;
		map[6][5]=1;
		
		map[6][7]=1;
		map[7][6]=1;
		
		map[7][8]=1;
		map[8][7]=1;
		
		map[8][9]=1;
		map[9][8]=1;
		
		map[9][10]=1;
		map[10][9]=1;
		
		map[9][12]=1;
		map[12][9]=1;
		
		map[10][11]=1;
		map[11][10]=1;
		
		map[11][12]=1;
		map[12][11]=1;
		
		map[12][13]=1;
		map[13][12]=1;
		
		map[13][14]=1;
		map[14][13]=1;
		
		map[13][15]=1;
		map[15][13]=1;
		
		map[10][11]=1;
		map[11][10]=1;
		
		map[16][17]=1;
		map[17][16]=1;
		
		map[16][18]=1;
		map[18][16]=1;
		
		map[17][18]=1;
		map[18][17]=1;
	}
	
	public static void cmd_i(int a, int b) {
		map[a][b]=1;
		map[b][a]=1;
	}
	
	public static void cmd_d(int a, int b) {
		map[a][b]=0;
		map[b][a]=0;
	}
	

	public static void cmd_n(int x) {
		int cnt = 0;
		for(int i=1; i<MAX; i++) {
			if(map[x][i]==1) {
				cnt++;
			}
		}
		out.println(cnt);
	}
	
	public static void cmd_f(int x) {
		HashSet<Integer> ffs = new HashSet<Integer>();
		for(int i=1; i<MAX; i++) {
			if(map[x][i]==1) {
				for(int j=1; j<MAX; j++) {
					if(j==x || map[x][j]==1) continue;
					if(map[i][j]==1) {
						ffs.add(j);
					}
				}
				
			}
		}
		out.println(ffs.size());
	}
	
	public static void cmd_s(int a, int b) {
		int res=-1;
		int[] visited = new int[MAX];
		
		Queue<Integer> que = new ArrayDeque<Integer>();
		que.add(a);
		visited[a]=0;
		
		while(!que.isEmpty()) {
			int cur = que.poll();
			if(cur==b) {
				res = visited[cur];
				break;
			}
			for(int i=1; i<MAX; i++) {
				if(map[cur][i]==1 && visited[i]==0 && i!=a) {
					que.add(i);
					visited[i] = visited[cur]+1;
				}
			}
		}
		if(res==-1) {
			out.println(NOCON);
		} else {
			out.println(res);
		}
	}
	
	public static void doCmd() {
		String cmd = sr.next();
		
		switch (cmd) {
	        case "i":
	        	cmd_i(sr.nextInt(), sr.nextInt());
	            break;
	        case "d":
	        	cmd_d(sr.nextInt(), sr.nextInt());
	        	break;
	        case "n":
	        	cmd_n(sr.nextInt());
	        	break;
	        case "f":
	        	cmd_f(sr.nextInt());
	        	break;
	        case "s":
	        	cmd_s(sr.nextInt(), sr.nextInt());
	        	break;
	        case "q":
	    		out.flush();
	    		out.close();
	        	System.exit(0);
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		
		initMap();

		while(true) {
			doCmd();

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