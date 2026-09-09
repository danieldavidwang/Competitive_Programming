#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int N, W, D, w[MM], t[MM], r[MM];
vector<int> adj[MM];
bool vis[MM];
queue<int> q;
struct node { int l, r, v; } seg[MM*3];

void fun(int l, int r, int rt) {
    seg[rt].l = l; seg[rt].r = r;
    if (l == r) { seg[rt].v = w[l]+t[l]; return; }
    int mid = (l+r)/2;
    fun(l, mid, 2*rt);
    fun(mid+1, r, 2*rt+1);
    seg[rt].v = min(seg[2*rt+1].v, seg[2*rt].v);
}

void update(int pos, int val, int rt) {
    if(seg[rt].l == seg[rt].r) { seg[rt].v = val;  return; }
    int mid = (seg[rt].l + seg[rt].r)/2;
    pos <= mid ? update(pos, val, 2*rt) : update(pos, val, 2*rt+1);
    seg[rt].v = min(seg[2*rt].v, seg[2*rt+1].v);
}

int main() {
    cin >> N >> W >> D;
    for (int i = 1, a, b; i <= W; i++) { cin >> a >> b;  adj[b].push_back(a); }
    memset(w, 1, sizeof(w));
    
    w[N] = 0;
    vis[N] = 1;
    q.push(N);
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u])
            if (!vis[v]) { vis[v] = 1; q.push(v); w[v] = w[u]+1; }
    }
    for (int i = 1; i <= N; i++) { cin >> r[i]; t[r[i]] = i-1; }
    fun(1, N, 1);
    for (int i = 1, x, y; i <= D; i++) {
        cin >> x >> y;
        int px = r[x], py = r[y];
        swap(t[px], t[py]);
        swap(r[x], r[y]);
        update(px, w[px]+t[px], 1);
        update(py, w[py]+t[py], 1);
        cout << seg[1].v << '\n';
    }
}