#pragma GCC optimize (2)
#include <bits/stdc++.h>
#define INF 0x3f3f3f
using namespace std;
const int MM = 1e2+2;
int t, n, m, sm, g[MM][MM];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> g[i][j];
        for (int i = 1; i < m; i++) {
			for (int j = 0; j < n; j++) {
				sm = INF;
				for (int x=0;x<n;x++) if (x!=j) sm = min(g[x][i-1], sm);
			g[j][i] += sm;
			}
		}
		sm = INF;
		for (int i = 0; i < n; i++) sm = min(g[i][m-1], sm);
		cout << sm << '\n';
    }
}