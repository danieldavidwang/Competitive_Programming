#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7, MM = 1e6+6;
ll N, M, dp[MM];

int solve() {
    dp[1] = 1; ll ans = dp[1];
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i-1];
        if (i >= M) dp[i] = (dp[i] + dp[i-M]) % MOD;
        ans = (ans+dp[i]) % MOD;
    }
    return ans;
}

int main() {
    cin >> N >> M;
    cout << solve()+1 << '\n';
    return 0;
}