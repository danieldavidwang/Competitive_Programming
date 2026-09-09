#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MM = 2e3+9;
int N, M, B, Q, dis[MM];
bool vis[MM];
vector<pii> adj[MM];

int main() {
    cin >> N >> M >> B >> Q;
    for(int i = 1, u, v, w; i <= M; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    memset(dis, 100, sizeof(dis));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[B] = 0; pq.push({0, B});
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto [v, w]: adj[u]){
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
    for (int i = 1, u; i <= Q; i++) { cin >> u; cout << (vis[u] ? dis[u]:-1) << '\n'; }
}