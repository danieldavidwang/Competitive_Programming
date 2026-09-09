#include <bits/stdc++.h>
using namespace std;
const int MM = 20, M = (1 << MM);
int n, pos; long double prob[MM][MM], dp[M];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; pos = (1 << n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> prob[i][j];
            prob[i][j] /= 100;
        }
    }
    dp[0] = 1.0L;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int bitmask = 0; bitmask < (1 << n); bitmask++) {
                if (i != __builtin_popcount(bitmask) || bitmask & (1 << j)) continue;
                else { int neww = bitmask | (1 << j); dp[neww] = max(dp[neww], prob[j][i] * dp[bitmask]); }
            }
        }
    }
    printf("%.6Lf\n", 100.0L * dp[pos-1]);
}