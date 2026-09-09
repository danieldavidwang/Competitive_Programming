#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 4e2+2;
int n, k, cows[MM], dp[MM][MM];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> cows[i];
    memset(dp, 0x7f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int C = j-i+1, t = 0;
            for (int k = i; k <= j; k++) t += max(0, C-cows[k]-1);
            for (int l = 0; l <= k; l++) dp[j+1][l+1] = min(dp[i][l]+t, dp[j+1][l+1]);
        }
    }
    cout << dp[n][k+1] << '\n'; return 0;
}