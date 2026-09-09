import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class MainS3MeasuringTraffic {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	
	static final String NONE="none", ON="on", OFF="off";
	static int N=0;
	static String road[];
	static int stp[], edp[];
	public static void main(String[] args) throws IOException {
		try {
			N = readInt();
			road = new String[N];
			stp = new int[N];
			edp = new int[N];
			for(int i=0; i<N; i++) {
				road[i] = next();
				stp[i] = readInt();
				edp[i] = readInt();
			}
			
			ArrayList<String> rArr = new ArrayList<String>();
			ArrayList<Integer> xArr = new ArrayList<Integer>();
			ArrayList<Integer> yArr = new ArrayList<Integer>();
			int mx = Integer.MIN_VALUE, mn = Integer.MAX_VALUE;
			for(int i=0; i<N; i++) {
				String r = road[i];
				int st = stp[i];
				int ed = edp[i];
				if(!r.equals(NONE)) {
					if(mx!=Integer.MIN_VALUE) {
						rArr.add(NONE);
						xArr.add(mx);
						yArr.add(mn);
						mx = Integer.MIN_VALUE; mn = Integer.MAX_VALUE;
					}
					
					rArr.add(r);
					xArr.add(st);
					yArr.add(ed);
				} else {
					mx = Math.max(mx, st);
					mn = Math.min(mn, ed);
				}
			}
			if(mx!=Integer.MIN_VALUE) {
				rArr.add(NONE);
				xArr.add(mx);
				yArr.add(mn);
			}

			int idx = 0, minDif = Integer.MAX_VALUE;
			for(int i=0; i<rArr.size(); i++) {
				String r = rArr.get(i);
				int st = xArr.get(i);
				int ed = yArr.get(i);
				if(r.equals(NONE)) {
					int d = ed - st;
					if(d < minDif) {
						minDif = d;
						idx = i;
					}
				}
			}
			
			int st0 = xArr.get(idx), ed0=yArr.get(idx);
			for(int i=idx-1; i>=0; i--) {
				String r1 = rArr.get(i);
				int st1 = xArr.get(i), ed1 = yArr.get(i);
				if(r1.equals(NONE)) {
					st0 = Math.max(st0, st1);
					ed0 = Math.min(ed0, ed1);
				} else if(r1.equals(ON)) {
					st0 = st0 - ed1;
					ed0 = ed0 - st1;
					if(st0<0) st0=0;
					if(ed0<0) ed0=0;
				} else {
					st0 = st0 + st1;
					ed0 = ed0 + ed1;
					if(st0<0) st0=0;
					if(ed0<0) ed0=0;
				}
			}
			out.println(st0 + " " + ed0);
			
			st0 = xArr.get(idx); ed0=yArr.get(idx);
			for(int i=idx+1; i<rArr.size(); i++) {
				String r1 = rArr.get(i);
				int st1 = xArr.get(i), ed1 = yArr.get(i);
				if(r1.equals(NONE)) {
					st0 = Math.max(st0, st1);
					ed0 = Math.min(ed0, ed1);
				} else if(r1.equals(ON)) {
					st0 = st0 + st1;
					ed0 = ed0 + ed1;
					if(st0<0) st0=0;
					if(ed0<0) ed0=0;
				} else {
					st0 = st0 - ed1;
					ed0 = ed0 - st1;
					if(st0<0) st0=0;
					if(ed0<0) ed0=0;
				}
			}
			out.println(st0 + " " + ed0);
			
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