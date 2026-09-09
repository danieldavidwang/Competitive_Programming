#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5, MOD = 1e4+7;
long long n, dp[MM], pre[26];
string s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    n = s.size();
    
    for (int i = 1; i <= n; i++) {
        long long chr = s[i-1]-'a';
        if (pre[chr] == 0) dp[i] = (2*dp[i-1]+1) % MOD;
        else dp[i] = (2*dp[i-1] - dp[pre[chr]-1] + MOD) % MOD;
        pre[chr] = i;
    }
    cout << dp[n] << '\n'; return 0;
}