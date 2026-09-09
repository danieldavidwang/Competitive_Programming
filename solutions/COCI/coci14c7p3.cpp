#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int N, ans = INT_MAX, dp[3][MM], v[3][MM];

int solve(int a, int b, int c) {
    memset(dp, 0x3f, sizeof(dp));
    dp[a][0] = v[a][0];
    for (int i = 1; i < N; i++) {
        dp[a][i] = dp[a][i-1] + v[a][i];
        dp[b][i] = min(dp[b][i-1] + v[b][i], dp[a][i-1] + v[b][i]);
        dp[c][i] = min(dp[c][i-1] + v[c][i], dp[b][i-1] + v[c][i]);
    }
    return dp[c][N-1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < N; j++)
            cin >> v[i][j];

    ans = min(ans, solve(0, 1, 2));
    ans = min(ans, solve(0, 2, 1));
    ans = min(ans, solve(1, 0, 2));
    ans = min(ans, solve(1, 2, 0));
    ans = min(ans, solve(2, 0, 1));
    ans = min(ans, solve(2, 1, 0));
    cout << ans << '\n';
    return 0;
}