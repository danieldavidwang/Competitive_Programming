#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5+5;
vector<int> adj(MM), ind(MM); vector<bool> vis(MM);
int n, ans;

void search(int u, int mob) {
    stack<pair<int, int>> st; st.push({u, mob});
    while (!st.empty()) {
        auto [node, current_mob] = st.top();
        st.pop();
        ans += current_mob;
        vis[node] = 1;
        ind[adj[node]]--;
        if (!vis[adj[node]] && (!ind[adj[node]] || current_mob)) st.push({adj[node], current_mob ^ 1});
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int x = 1; x <= n; x++) {
        cin >> adj[x];
        ind[adj[x]]++;
    }
    for (int x = 1; x <= n; x++) if (!vis[x] && !ind[x]) search(x, 1);
    for (int x = 1; x <= n; x++) if (!vis[x]) search(x, 0);
    cout << ans << '\n';
    return 0;
}