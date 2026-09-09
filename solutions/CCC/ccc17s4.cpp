#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<int, 4> E;
const int MM = 1e5+5;
int N, M, D, p[MM], last;
vector<E> edges;

int find(int d) {
    if (d != p[d]) p[d] = find(p[d]);
    return p[d];
}

int main() {
    cin >> N >> M >> D;
    for (int i = 1; i <= N; i++) p[i] = i;
    for (int i = 1, u, v, w; i <= M; i++) {
        cin >> u >> v >> w;
        edges.push_back({w, i >= N, u, v});
    }
    
    sort(edges.begin(), edges.end());
    int ans = 0;
    
    for (int i = 0; i < edges.size(); i++) {
        int t = edges[i][1], u = edges[i][2], v = edges[i][3], fu = find(u), fv = find(v);
        if (fu != fv) { p[fu] = fv; ans+=t; last = i; }
    }
    
    if (edges[last][1]) {  
        for (int i = 1; i <= N; i++) p[i] = i;
        for (int i = 0; i < last; i++) {
            auto [w, t, u, v] = edges[i];
            if (!t || w < edges[last][0]) {
                int fu = find(u), fv = find(v);
                if (fu != fv) p[fu] = fv;
            }
        }
        for (int i = last+1; i < edges.size(); i++) {
            auto [w, t, u, v] = edges[i];
            if (!t && w <= D) {
                int fu = find(u), fv = find(v);
                if (fu != fv) { ans--;  break; }
            }
        }
    }
    cout << ans << '\n';
}