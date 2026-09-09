#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3+3;
int N, a[MM], b[MM], dp[MM][MM];
char s[MM], t[MM];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> s[i];
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) cin >> t[i];
    for (int i = 1; i <= N; i++) cin >> b[i];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if ((s[i] == 'W' && a[i]>b[j] || t[j] == 'W' && a[i]<b[j]) && s[i] != t[j]) dp[i][j] = dp[i-1][j-1]+a[i]+b[j];
            dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
        }
    }
    cout << dp[N][N] << '\n';
}