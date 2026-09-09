#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int N, K; 

void solve() {
    cin >> N >> K;
    vector<int> att(N);

    for (int i = 0; i < N; i++) cin >> att[i];

    int day = (N + K - 1) / K;

    int minVisit = N % K;

    if (minVisit == 0) minVisit = K;

    vector<int> preMax(N, 0), suffMax(N, 0);

    vector<long long> dp(N, 0), revDPMax(N, 0), revSumMax(N, 0);

    for (int i = 0; i < K; i++) {
       if (i > 0) preMax[i] = max(preMax[i - 1], att[i]);
       else preMax[i] = att[i];
       dp[i] = preMax[i];
    }

    for (int i = K - 1; i >= 0; i--) {
        if (i < K - 1) suffMax[i] = max(suffMax[i + 1], att[i]);
        else suffMax[i] = att[i];

        revSumMax[i] = max(suffMax[i] + (i > 0 ? dp[i - 1] : 0), (i < K - 1 ? revSumMax[i + 1] : 0));
        revDPMax[i] = max(dp[i], (i < K - 1 ? revDPMax[i + 1] : 0));
    }

    for (int d = 1; d < day; d++) {
        for (int i = K * d; i < min(N, K * (d + 1)); i++) {
           if (i > K * d) preMax[i] = max(preMax[i - 1], att[i]);
           else preMax[i] = att[i];
        }

        for (int i = min(N, K * (d + 1)) - 1; i >= K * d; i--) {
           if (i < min(N, K * (d + 1)) - 1) suffMax[i] = max(suffMax[i + 1], att[i]);
           else suffMax[i] = att[i];
        }

        int it = K * (d - 1) + minVisit - 1;

        for (int i = it + K; i - it <= K && it < K * d && i < N; i++) {
           dp[i] = max(preMax[i] + revDPMax[it], revSumMax[it + 1]);
           it += (i - it == K);
        }

        for (int i = min(N, K * (d + 1)) - 1; i >= K * d; i--) {
           revSumMax[i] = max(suffMax[i] + (i > 0 ? dp[i - 1] : 0), (i < min(N, K * (d + 1)) - 1 ? revSumMax[i + 1] : 0));
           revDPMax[i] = max(dp[i], (i < min(N, K * (d + 1)) - 1 ? revDPMax[i + 1] : 0));
        }
    }
    cout << dp[N - 1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve(); return 0;
}