#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+1;
int N, M, in[MM]; vector<int> adj[MM], order; queue<int> q;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cin >> N >> M;
    for (int i = 0, u, v; i < M; i++) { cin >> u >> v; adj[v].push_back(u); in[u]++; }
    for (int i = 1; i < N+1; i++) if (!in[i]) q.push(i);
    while(!q.empty()) {
        int u = q.front(); q.pop(); order.push_back(u);
        for(int v : adj[u]) if (--in[v] == 0) q.push(v);
    }
    if (order.size() != N) cout << "-1\n";
    else { cout << N << '\n'; for(int x : order) cout << x << " " << 1 << '\n'; }
}