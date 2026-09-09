#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3+3;
int D, I, R, dp[MM][MM];
string A, B;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> D >> I >> R >> A >> B;
    int n = A.size(), m = B.size();
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 && j == 0) dp[i][j] = 0;
            else if (j == 0) dp[i][j] = i * D;
            else if (i == 0) dp[i][j] = j * I;
            else {
                if (A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(min(dp[i-1][j-1]+R, dp[i-1][j]+D), dp[i][j-1]+I);
            }
        }
    }
    cout << dp[n][m] << '\n';
}