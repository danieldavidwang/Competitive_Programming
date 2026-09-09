#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MM = 1e5+5;
int N, M, K, A, B, ans = INT_MAX, dis[2][MM], s[MM];
vector<int> adj[MM];

void dijkstra(int st, int p) {
    memset(dis[p], 11, sizeof(dis[p]));
    priority_queue<pi> Q;
    Q.push({0, st}); dis[p][st] = 0;
    while (!Q.empty()) {
        int d = -(Q.top().first), u = Q.top().second; Q.pop();
        if (d > dis[p][u]) continue;
        for (int v: adj[u]) {
            if (d + 1 < dis[p][v]) {
                dis[p][v] = d+1;
                Q.push({-dis[p][v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M >> K >> A >> B;
    for (int i = 0; i < K; i++) cin >> s[i];
    for (int i = 0, u, v; i < M; i++) { cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u); }
    dijkstra(A, 0); dijkstra(B, 1);
    for (int i = 0; i < K; i++) ans = min(dis[1][s[i]]+dis[0][s[i]], ans);
    cout << ans << '\n';
}