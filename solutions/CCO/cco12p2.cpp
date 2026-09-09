#include <bits/stdc++.h>
using namespace std;
const int MM = 2e4+4;
typedef long long ll;
typedef pair<int, int> pi;
int N, M, dis1[MM], dis2[MM];
vector<pi> adj[MM], rev[MM];
vector<array<int, 3>> edge;

void dij(int s, vector<pi> adj[], int dis[]) {
    fill(dis, dis+MM, 1e9);
    priority_queue<pi, vector<pi>, greater<pi>> q;
    q.push({0, s});
    dis[s] = 0;
    while (!q.empty()) {
        auto [d, u] = q.top(); q.pop();
        if (d > dis[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dis[v] > dis[u] + w) { dis[v] = dis[u]+w;  q.push({dis[v], v}); }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 1, u, v, w; i <= M; i++) {
        cin >> u >> v >> w;
        edge.push_back({u, v, w});
        adj[u].push_back({v, w});
        rev[v].push_back({u, w});
    }
    dij(1, adj, dis1);
    dij(N, rev, dis2);
    if (dis1[N] >= 1e9) { cout << -1 << '\n';  return 0; }
    int ans = 1e9;
    for (auto [u, v, w] : edge) {
        int temp = dis1[u] + w + dis2[v];
        if (temp > dis1[N] && temp < ans) ans = temp;
    }
    ans >= 1e9 ? cout << -1 << '\n' : cout << ans << '\n' ;
}