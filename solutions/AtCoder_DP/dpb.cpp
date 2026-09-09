#include <bits/stdc++.h>
using namespace std;
const long long MM = 1e5+5;
long long N, K, costs[MM], dp[MM];

long long solve(long long x) {
    long long ans = LLONG_MAX;
    if (x == N-1) return 0;
    if (dp[x] != -1) return dp[x];
    for (int i = 1; i <= K; i++) {
        if (x+i >= N) break;
        ans = min(ans, (solve(x+i)+abs(costs[x+i]-costs[x])));
    }
    return dp[x]=ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> N >> K;
    for (long long i = 0; i < N; i++) cin >> costs[i];
    cout << solve(0) << '\n';
}