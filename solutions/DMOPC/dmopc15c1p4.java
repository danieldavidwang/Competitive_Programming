import java.io.*;
import java.util.*;

public class Main {
	public static Queue<Integer> p(int N) {
	    Queue<Integer> p = new LinkedList<Integer> ();
		boolean[] sieve = new boolean[N + 1];
		p.offer (2);

		for (int i = 2; i <= N; i++)
			if (!sieve[i] && i%2 != 0) {
				for (int x = i; x <= N; x += i) sieve[x] = true;
				p.offer (i);
			}
		return p;
	}

	public static int solve(Queue<Integer> p, int R, int C) {
		int poss = 0, d = 0, q, r;

		while (!p.isEmpty()) {
			d = C-p.poll();
			if (d == 0) poss++;
			else if (d > 0) {
				q = d / R;
				r = d % R;
				poss += 2 + 2*q ;
				if (r == 0) poss--;
			}
		}
		return poss;
	}

	public static void main (String[] args) throws IOException {
		BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
		String[] t = in.readLine().split (" ");
		int C = Integer.parseInt (t[0]);
		System.out.println (solve (p(C), Integer.parseInt (t[1]), C));
	}
}