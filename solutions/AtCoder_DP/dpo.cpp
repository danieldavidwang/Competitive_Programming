#pragma GCC optimize (2)
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MAX = 21, MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;

    vector<vector<int>> comp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> comp[i][j];

    const int m = (1 << n) - 1;
    vector<int> dp(m + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < m; ++i) {
        int curMan = __builtin_popcount(i);
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) continue;

            if (comp[curMan][j]) {
                int &val = dp[i | (1 << j)];
                val = (val + dp[i]) % MOD;
            }
        }
    }
    cout << dp[m] << '\n'; return 0;
}