#pragma GCC optimize (2)
#include <bits/stdc++.h>
#define mem(a,b) memset(a, b, sizeof(a))
#define INF 0x3f3f3f
using namespace std;
const int MM = 1e5+5;
int n, m, dis[MM], ans = -INF; bool vis[MM]; vector<int> adj[MM];

int dfs(int v) {
    vis[v] = 1;
    if (!adj[v].size()) dis[v] = 0;
    
    for (int u: adj[v]) {
        if (!vis[u]) dis[v] = max(dfs(u)+1, dis[v]);
        else dis[v] = max(dis[u]+1, dis[v]);
    }
    return dis[v];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    mem(dis, -1); mem(vis, false); cin >> n >> m;
    for (int i = 1, x, y; i <= m; i++) { cin >> x >> y; adj[x].push_back(y); }
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
    for (int i = 1; i <= n; i++) ans = max(dis[i], ans);
    cout << ans << '\n'; return 0;
}