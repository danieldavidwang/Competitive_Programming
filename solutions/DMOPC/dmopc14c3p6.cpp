#include<bits/stdc++.h>
using namespace std;
int N, W, v1, w1, v2, w2, v3, w3, dp[10004];

int main() {
    cin >> N >> W;
    for (int i = 1; i <= N; i++){
        cin >> w1 >> v1 >> w2 >> v2 >> w3 >> v3;
        for (int j = W; j >= w1; j--) {
            if (j >= w1) { dp[j] = max(dp[j], dp[j-w1] + v1); }
            if (j >= w2) { dp[j] = max(dp[j], dp[j-w2] + v2); }
            if (j >= w3) { dp[j] = max(dp[j], dp[j-w3] + v3); }
        }
    }
    cout << dp[W] << '\n';
}