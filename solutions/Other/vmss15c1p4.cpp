#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MM = 2002;
int T, N, M, G, g[MM], dis[MM], ans=0;
vector<pi> adj[MM];
priority_queue<pi, vector<pi>, greater<pi>> q;

int main() {
    cin >> T >> N >> M >> G;
    for (int i = 0; i < G; i++) cin >> g[i];
    for (int i = 1, u, v, w; i <= M; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    memset(dis, 1, sizeof(dis));
    dis[0] = 0; q.push({dis[0], 0});
    while (!q.empty()) {
        int d = q.top().first, u = q.top().second; q.pop();
        if (d > dis[u]) continue;
        for (pi e: adj[u]){
            int v = e.first, w = e.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
    for (int i = 0; i < G; i++) { if (dis[g[i]] < T) ans++; }
    cout << ans << '\n';
}