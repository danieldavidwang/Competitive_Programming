#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5, MOD = 1e9+7;
int N, K, out, pref[MM], dp[MM];

int fun(int a, int b) {
    if (a < 0) a = 0;
    int ans = pref[b];
    if (a) ans -= pref[a-1];
    return ans % MOD;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    dp[0] = 1;
    cin >> N >> K;
    
    for (int kid = 1, c; kid <= N; kid++) {
        cin >> c;
        pref[0] = dp[0];
        dp[0] = 0;
        for (int i = 1; i <= K; i++) pref[i] = (pref[i-1] + dp[i]) % MOD;
        for (int i = 0; i <= K; i++) dp[i] = fun(i-c, i);
    }
    out = dp[K];
    if (out < 0) out += MOD;
    printf("%d\n", out);
}