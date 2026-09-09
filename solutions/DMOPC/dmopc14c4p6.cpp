#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int MM = 5e5+5;
int n, f, r, dis1[MM], dis2[MM];
vector<int> adj[MM];

void dfs(int u, int pa, int d, int dis[]) {
    dis[u] = d;
    if (d > f) { f = d; r = u; }
    for (int v : adj[u]) { if (v != pa) dfs(v, u, d+1, dis); }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    for (int i = 1, u, v; i<n; i++) { cin >> u >> v; adj[u].pb(v); adj[v].pb(u); }
    dfs(1, 0, 0, dis1);
    f = 0; dfs(r, 0, 0, dis1);
    f = 0; dfs(r, 0, 0, dis2);
    for(int i = 1; i <= n; i++) { cout << max(dis1[i], dis2[i]) + 1 << '\n'; }
}