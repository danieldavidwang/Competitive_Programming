#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3+3, MOD = 1e9+7;
int h, w, dp[MM][MM];
char grid[MM];

int main() {
    scanf("%d%d", &h, &w);
    dp[1][0] = 1;
    for (int i = 1; i <= h; i++) {
        scanf("%s", grid+1);
        for (int j = 1; j <= w; j++) {
            if (grid[j] == '#') dp[i][j] = 0;
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }
    cout << dp[h][w] << '\n';
    return 0;
}