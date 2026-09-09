#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, MM = 2e5+2;
int n, x[MM], dis[MM]; long long k; bool vis[MM];

int main(){
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int cur = 1; ; cur=x[cur]) {
        int nxt = x[cur];
        if (vis[nxt]) k %= (dis[cur] - dis[nxt] + 1);
        if (k == 0) {
            cout << cur << '\n';
            return 0;
        }
        k--; dis[nxt] = dis[cur] + 1; vis[cur] = 1;
    }
    return 0;
}