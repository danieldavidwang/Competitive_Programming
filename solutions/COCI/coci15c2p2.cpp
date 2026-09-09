#pragma GCC optimize (2)
#include <bits/stdc++.h>
#define TRAV(a, c) for (const auto &a : c)
using namespace std;
const int MM = 21;
int n, m;
bool b[MM];
vector<int> v[MM];

int solve(int x) {
    if (x == n) return 1;
    int ans = solve(x+1);
    bool gud = 1;
    TRAV(u, v[x])
        if (b[u]) gud = 0;

    if (gud) {
        b[x] = 1;
        ans += solve(x+1);
        b[x] = 0;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        x--; y--; 
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cout << solve(0) << '\n';
    return 0;
}