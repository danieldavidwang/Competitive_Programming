#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+9;
int n, ans, st;
vector<int> adj[MM];

void dfs(int u, int pa, int d) {
    if (d > ans) { ans = d; st = u; }
    for (int v: adj[u]) if (v != pa) dfs(v, u, d+1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1, u, v; i <= n; i++) { cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u); }
    dfs(1, 0, 0); ans = 0; dfs(st, 0, 0);
    cout << ans << '\n';
}