#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+6, MOD = 1e9+7;
int n; ll dp[MM];

int main() {
    scanf("%d", &n);
    dp[1] = 1; dp[2] = 2;
    for (int i = 3; i <= n; i++) { dp[i] = (dp[i-1]+dp[i-3]) % MOD; dp[i]++; }
    cout << dp[n] << '\n';
}