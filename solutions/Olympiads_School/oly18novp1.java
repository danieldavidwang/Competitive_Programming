import java.io.*;
import java.util.*;

public class MainS3Segment_maxTasks {

	static PrintWriter out = new PrintWriter(System.out);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	

	public static void main(String[] args) throws IOException, InterruptedException {
		int n = readInt(); List<seg> a = new ArrayList<>();
		for(int i=0; i<n; i++) {
			a.add(new seg(readInt(), readInt()));
		}
		Collections.sort(a, (x, y) -> Integer.compare(x.end, y.end));
		int ans = 0, t = 0;
		for(seg e : a) {
			if(e.start >= t) { ans ++; t = e.end; }
		}
		System.out.println(ans);
	}
	static class seg {
		int start, end;
		seg(int s, int e) { start = s; end = e; }
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