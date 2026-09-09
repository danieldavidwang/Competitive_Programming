#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 4e2+4;
ll dp[MM][MM], psa[MM];

ll func(int l, int r) {
    ll ans = 1e18; if (dp[l][r] != -1) return dp[l][r]; if (l == r) return 0;
    for (int m = l; m < r; m++) ans = min(ans, func(l, m) + func(m+1, r) + psa[r]-psa[l-1]);
    return dp[l][r] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 1, x; i <= n; i++) { cin >> x; psa[i] = psa[i-1]+x; }
    cout << func(1, n) << '\n'; return 0;
}