#pragma GCC optimize (2)
#include <bits/stdc++.h>
#define pii pair<int, int>
#define mem(a, b) memset(a, b, sizeof(a))
#define mp make_pair
#define pb push_back
using namespace std;
const int MM = 2e5+5;
int N, M, dp[MM]; pii u; queue <pii > q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	vector<vector <pii> > l(N);
	mem(dp, 0);
	for (int m = 0, u, v, w; m < M; m++) {
		cin >> u >> v >> w; u--; v--;
		l[u].pb(mp(v, w)); l[v].pb(mp(u, w));
	}
	q.push(mp(0, 1e9));
	while (!q.empty()) {
		u = q.front(); q.pop();
		for (auto p: l[u.first]) {
			if (min(u.second, p.second) > dp[p.first]) {
				dp[p.first] = min(u.second, p.second);
				q.push(mp(p.first, min(u.second, p.second)));
			}
		}
	}
	cout << 0 << '\n';
	for (int i = 1; i < N; i++) cout << dp[i] << '\n';
}