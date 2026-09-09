#include<bits/stdc++.h>
using namespace std;
int N, H, g, h, q, t;
long long dp[3][5003];

int main() {
    cin >> N >> H;
    for (int i = 1, prev = 0, curr = 1; i <= N; i++) {
        cin >> g >> h >> q >> t;
        memset(dp[curr], 0, sizeof(dp[curr]));
        for (int j = h; j <= H; j++) dp[curr][j] = g+dp[prev][j-h];
        for (int j = h; j+t <= H; j++) dp[curr][j+t] = max(dp[curr][j]+q, dp[curr][j+t]);
        for (int j = 1; j <= H; j++) dp[curr][j] = max(dp[prev][j], dp[curr][j]);
        swap(prev, curr);
    }
    cout << dp[N&1][H] << '\n';
}