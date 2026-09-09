#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e4+4;
struct Ed{ int u, v, w; };
int N, M, D, parent[MM], ans; vector<Ed> edge; vector<int> dest;
int set_find(int d) { return parent[d] == d? parent[d]: parent[d] = set_find(parent[d]); }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> D;
    for(int i=1; i<=N; i++) parent[i] = i;
    for(int i=1, u, v, w; i<=M; i++) {
        cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }
    sort(edge.begin(), edge.end(), [](Ed &a, Ed &b){ return a.w>b.w;});
    for(int i=0, x; i<D; i++){
        cin >> x; dest.push_back(x);
    }
    for(int i=0, j=0; j < dest.size(); j++){
        int d = dest[j];
        while(set_find(d) != set_find(1)) {
            int u = edge[i].u, v = edge[i].v, w= edge[i].w;
            int fu = set_find(u), fv = set_find(v);
            if(fu != fv) { parent[fu] = fv; ans = w; }
            i++;
        }
    }
    cout << ans << endl;
}