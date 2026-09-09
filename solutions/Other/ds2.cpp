#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+1;
int N, M, p[MM+1]; vector<int> edge;
int Find(int d) { return (d == p[d]) ? (p[d]) : p[d] = Find(p[d]); }

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) p[i] = i;
    for (int i = 1, u, v; i <= M; i++) {
        cin >> u >> v;
        int fu = Find(u), fv = Find(v);
        if (fu != fv) { edge.push_back(i); p[fu] = fv; }
        if (edge.size() == N-1) break;
    }
    if (edge.size() < N-1) printf("Disconnected Graph\n");
    else { for(int x: edge) cout << x << '\n'; }
}