#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MM = 1e3+9;
int N, M, dis[MM];
bool vis[MM];
vector<pii> adj[MM];

int main() {
    cin >> N >> M;
    for(int i = 1, u, v, w; i <= M; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    memset(dis, 1, sizeof(dis));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[1] = 0; pq.push({0, 1});
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
    for (int i = 1; i <= N; i++) cout << (vis[i] ? dis[i]:-1) << '\n';
}