#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int n, indeg[MM]; vector<int> adj[MM], cnt; queue<int> q;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cin >> n;
    for(int i=1, m; i<=n; i++) {
        cin >> m;
        for(int j=1, x; j<=m; j++) {
            cin>>x; adj[x].push_back(i); indeg[i]++;
        }
    }
    for(int i=1; i<=n; i++) if(!indeg[i]) q.push(i);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        cnt.push_back(u);
        for(int v : adj[u]) if(--indeg[v] == 0) q.push(v);
    }
    for(int i=0; i<n; i++) cout << cnt[i] << " \n"[i==n-1];
}