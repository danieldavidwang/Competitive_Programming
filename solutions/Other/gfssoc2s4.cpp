#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5+3;
typedef long long ll;
typedef pair<ll, int> pli;
int N, M, D;
vector<pli> adj[MM], rev[MM];
ll d1[MM], d2[MM];
bool vis[MM];

void dijkstra(int st, vector<pli> adj[], ll dis[]){
    fill(dis, dis+MM, 1e18); fill(vis, vis+MM, 0);
    priority_queue<pli, vector<pli>, greater<pli>> q;
    dis[st] = 0;
    q.push({dis[st], st});
    while (!q.empty()) {
        int u = q.top().second; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [w, v] : adj[u])
            if (dis[v] > dis[u] + w) { dis[v] = dis[u] + w; q.push({dis[v], v}); }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 1, u, v, w; i <= M; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({w, v}); 
        rev[v].push_back({w, u});
    }
    dijkstra(1, adj, d1); 
    dijkstra(N, rev, d2);
    cin >> D; ll ans = d1[N];
    for (int i = 1, u, v, w; i <= D; i++){
        cin >> u >> v >> w;
        if (d1[u] + w + d2[v] < ans)  ans = d1[u] + w + d2[v];
    }
    if (ans == 1e18) cout << "-1\n";
    else cout << ans << '\n';
    return 0;
}