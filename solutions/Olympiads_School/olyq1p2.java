import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
	static PrintWriter out = new PrintWriter(System.out);
	static FastReader sr = new FastReader();

	static int N;
	static int[] inp = null;
	ArrayList<Integer> cnt = null;

	public static void main(String[] args) throws IOException {
		try {
			N = sr.nextInt();
			inp = new int[N];
			int dif=0, pre=0;
			int cnt=0;
			for(int i=0; i<N; i++) {
				int nt = sr.nextInt();
				inp[i] = nt;
				if(i==0) continue;
				else if(i==1) {
					cnt = 1;
					dif=Integer.signum(nt-inp[0]);
					pre=dif;
				} else {
					dif=Integer.signum(nt-inp[i-1]);
					if(dif==0) continue;
					else if(dif != pre) {
						cnt++;
						pre=dif;
					}
				}
			}
			out.println(cnt+1);
			
		} finally {
			out.flush();
			out.close();
		}
		
	}	
	
	static class Pair {
		int x, y;
		Pair(int x0, int y0) {
			x=x0;
			y=y0;
		}
		
	    @Override
	    public boolean equals(Object o) {
	        if (o == this) return true;

	        if (!(o instanceof Pair)) return false;
	         
	        Pair p = (Pair) o;
	        return (Integer.compare(x, p.x)==0 && Integer.compare(y, p.y)==0);
	    }
	    
	    @Override
	    public String toString() {
	        return "(" + this.x + ", " + this.y + ") ";
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