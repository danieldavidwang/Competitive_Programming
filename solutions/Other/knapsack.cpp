#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 5e3+3;
int N, M;
long long ans = -1e18, dp[MM];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    for (int i = 1, amt, c, val; i <= N; i++) {
        cin >> amt >> c >> val;
        for (int k = 1; k <= amt; k *= 2) {
            long long w = (long long)k*c, v = (long long)k*val;
            for (int j = MM-1; j >= w; j--) dp[j] = max(dp[j], dp[j-w]+v);
            amt -= k;
        }
        if (amt) {
            long long w = (long long)amt*c, v = (long long)amt*val;
            for (int j = MM-1; j >= w; j--) dp[j] = max(dp[j-w]+v, dp[j]);
        }
    }
    for (int i = 1, c, f; i <= M; i++) {
        cin >> c >> f;
        ans = max(dp[c]-f, ans);
    }
    cout << ans << '\n';
}