#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int n, maxx; vector<pi> adj[100001];
long long sum = 0;

void dfs(int c, int p, int d) {
    maxx = max(d, maxx);
    for (auto edge: adj[c]) {
        int nxt = edge.first, w = edge.second;
        if (nxt != p) dfs(nxt, c, d+w);
    }
}

int main() {
    cin >> n;
    for (int i = 1, u, v, w; i <= n; i++) {
        cin >> u >> v >> w; sum += w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(0, -1, 0);
    cout << 2*sum-maxx << '\n';
}