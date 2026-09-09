#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+9;
int N, M, rt, cnt, far, len;
vector<int> adj[MM];
bool nome[MM];

void depth1(int u, int par) {
    for (int v: adj[u]) {
        if (v == par) continue;
        else {
            depth1(v, u);
            nome[u] |= nome[v];
        }
    }
    cnt += nome[u];
}

void depth2(int u, int par, int dis) {
    if (dis > len) { far = u; len = dis; }
    for (int v: adj[u]) if (v != par && nome[v]) depth2(v, u, dis+1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0, x; i < M; i++) { cin >> x; nome[x] = 1; rt = x; }
    for (int i = 1, u, v; i < N; i++) { cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u); }
    depth1(rt, -1); depth2(rt, -1, 0); depth2(far, -1, 0);
    cout << 2*(cnt-1) - len << '\n';
    return 0;
}