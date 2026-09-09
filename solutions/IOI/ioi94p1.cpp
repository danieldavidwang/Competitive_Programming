#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e2+2;
int n, t[MM][MM], dp[MM][MM];

int solve(int lvl, int idx) {
    if (lvl == n-1) return t[lvl][idx];
    else if (dp[lvl][idx] != -1) return dp[lvl][idx];
    else {
        int ans = max(solve(lvl+1, idx), solve(lvl+1, idx+1)) + t[lvl][idx];
        dp[lvl][idx] = ans; return ans;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> t[i][j];

    cout << solve(0, 0) << '\n';
}