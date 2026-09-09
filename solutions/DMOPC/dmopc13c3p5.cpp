#include <bits/stdc++.h>
using namespace std;
int M, U, R, dp[159][309][109], V[159], T[159], F[159];

int main() {
    cin >> M >> U >> R;
    for (int i = 1; i <= R; i++) cin >> V[i] >> T[i] >> F[i];
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= M; j++) {
            for (int k = 1; k <= U; k++) {
                if (T[i] > j || F[i] > k) dp[i][j][k] = dp[i-1][j][k];
                else dp[i][j][k] = max(dp[i-1][j-T[i]][k-F[i]]+V[i], dp[i-1][j][k]);
            }
        }
    }
    cout << dp[R][M][U] << '\n';
}