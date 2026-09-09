#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
const int MM = 1e6+6;
int N, M;
vector<pi> adj[MM];
bool vis[MM];
pi dis[MM];

int main() {
    cin >> N >> M;
    for(int i = 1, u, v, w; i <= M; i++) { cin >> u >> v >> w; adj[u].push_back({v,w}); adj[v].push_back({u,w}); }
    
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    memset(dis, 1, MM);
    dis[1] = {0, 0};
    pq.push({dis[1], 1});
    
    while (!pq.empty()) {
        pii curr = pq.top(); pq.pop();
        pi d = curr.first; int u = curr.second;
        if (vis[u]) continue;
        vis[u] = 1;
        for (pi e : adj[u]) {
            int v = e.first, w = e.second;
            pi tmp = {dis[u].first + w, dis[u].second+1};
            if (dis[v] > tmp) {
                dis[v] = tmp;
                pq.push({dis[v], v});
            }
        }
    }
    if(!vis[N]) cout << -1 << '\n';
    else cout << dis[N].first << " " << dis[N].second << '\n';
}