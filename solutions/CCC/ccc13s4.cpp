#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+6;
int N, M, p, q; vector<int> graph[MM]; bitset<MM> vis;

void dfs(int c) {
    if (vis[c]) return;
    else vis[c] = 1;
    for (auto x: graph[c]) dfs(x);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0, x, y; i < M; i++) { cin >> x >> y; graph[x].push_back(y); }
    cin >> p >> q;
    dfs(p); bool b = vis[q]; vis.reset(); dfs(q); bool bb = vis[p];
    if (b && !bb) cout << "yes\n";
    else if (!b && bb) cout << "no\n";
    else cout << "unknown\n";
}