#include <bits/stdc++.h>
using namespace std;
const int MM = 2e3+5, MK = 2e2+5;
int dis[MM][MK], hl, n, m, x, y, t, h;
bool vis[MM][MK];

int main() {
    cin >> hl >> n >> m;
    vector<vector<array<int, 3>>> adj(n+1);
    while (m--) {
        cin >> x >> y >> t >> h;
        adj[x].push_back({-t, h, y});
        adj[y].push_back({-t, h, x});
    }
    int st, fin; cin >> st >> fin;
    memset(dis, 2, sizeof(dis));
    priority_queue<array<int,3>> q;
    q.push({0, hl, st}); dis[st][hl] = 0;
    
    while (!q.empty()) {
        array<int,3> curr = q.top();  q.pop();
        int t = curr[0], k = curr[1], u = curr[2];
        if (vis[u][k]) continue;
        vis[u][k] = true;
        if (u == fin) { cout << -t << endl; return 0;}
        for (auto e : adj[u]) {
            int w = e[0], h = e[1], v = e[2];
            if (k > h && dis[v][k-h] > -t - w) {
                dis[v][k-h] = -t - w;
                q.push({-dis[v][k-h], k-h, v});
            }
        }
    }
    cout << "-1\n";
    return 0;
}