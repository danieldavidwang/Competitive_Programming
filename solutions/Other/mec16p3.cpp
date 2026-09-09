#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 103;
int N, T, dp[MM];

int main() {
    cin >> N >> T;
    for (int i = 1, m; i <= N; i++) {
        cin >> m;
        vector<pi> lvl;
        int w = 0, v = 0;
        for (int k = 1, t, x; k <= m; k++) {
            cin >> t >> x;
            v += x; w += t;
            lvl.push_back({w, v});
        }
        for (int j = T; j >= 0; j--) {
            for (auto [w, v] : lvl) {
                if (w <= j) dp[j] = max(dp[j-w]+v, dp[j]);
            }
        }
    }
    cout << dp[T] << '\n';
}