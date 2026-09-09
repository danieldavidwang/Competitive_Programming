#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+6;
typedef pair<int, int> pi;
int N, M, a[MM], dis[MM];
vector<int> adj[MM];
vector<pi> dis1[MM], dis2[MM];
bool vis[MM];

void bfs(int start, vector<pi> d[]) {
    queue<int> q;
    memset(vis, 0, sizeof(vis));
    q.push(start);
    dis[start] = 0; vis[start] = true;
    while (!q.empty()) {
        int u = q.front(), val = a[u]; q.pop();
        if (d[val].size() < 2) d[val].push_back({u, dis[u]});
        for (int v : adj[u])
            if (!vis[v]) { q.push(v); dis[v] = dis[u]+1; vis[v] = 1; }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1, u, v; i <= M; i++) { cin >> u >> v; adj[v].push_back(u); adj[u].push_back(v); }
    bfs(N, dis2); bfs(1, dis1); 
    int ans = INT_MAX;
    
    for (int i = 1; i <= N; i++)
        for (pi u: dis1[i])
            for (pi v: dis2[i])
                if(u.first != v.first) ans = min(ans, u.second + v.second);
                
    if (ans == INT_MAX) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}