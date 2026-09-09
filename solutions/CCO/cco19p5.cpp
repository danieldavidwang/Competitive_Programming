#include <bits/stdc++.h>
#define s size()
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
int N, M, start; ll ans; set<int> grid[MM];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    for (int x = 0, a, b; x < M; x++) { cin >> a >> b; grid[a].insert(b); }
    for (int i = 1; i <= N; i++) {
        ans += grid[i].s;
        if (grid[i].s) {
            start = *grid[i].begin();
            grid[i].erase(grid[i].begin());
            if (grid[start].s <= grid[i].s) swap(grid[i], grid[start]);
            for (auto j: grid[i]) grid[start].insert(j);
        }
    }
    cout << ans << '\n';
}