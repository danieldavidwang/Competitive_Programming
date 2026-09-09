#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 5005;
typedef pair<int, int> pi;
int N, M, K, D, dis[MM], c[MM], cost[MM];
vector<pi> adj[MM];
bool visited[MM];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 1, u, v, w; i <= M; i++) { cin >> u >> v >> w; adj[u].push_back({v, w}); adj[v].push_back({u, w}); }
    cin >> K;
    for (int j = 1; j <= K; j++) cin >> c[j] >> cost[j];
    cin >> D;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    memset(dis, 0x3f, sizeof(dis));
    dis[D] = 0;
    pq.push({dis[D], D});
    
    while (!pq.empty()) {
        int d = pq.top().first, u = pq.top().second; pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        
        for (pi p : adj[u]) {
            int v = p.first, w = p.second;
            if (dis[v] > dis[u] + w) { dis[v] = dis[u] + w ; pq.push({dis[v], v}); }
        }
    }
    
    int ans = INT_MAX;
    for (int i = 1; i <= K; i++) ans = min(dis[c[i]]+cost[i], ans);
    cout << ans << '\n';
    return 0;
}