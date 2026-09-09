#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3+3;
int n, m, dp[MM][MM];
string a, b;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> a >> b;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (!j) dp[i][j] = (i+2)/3;
            else if (!i) dp[i][j] = (j+2)/3;
            else {
                if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = dp[i-1][j-1] + 1;
                for (int k = 1; k <= 3; k++) { if (i >= k) dp[i][j] = min(dp[i-k][j] + 1, dp[i][j]); if (j >= k) dp[i][j] = min(dp[i][j-k] + 1, dp[i][j]); }
            }
        }
    }
    cout << dp[n][m] << '\n';
}