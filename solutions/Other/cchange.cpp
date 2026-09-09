#include <bits/stdc++.h>
using namespace std;
int x, n, values[101];

void solve() {
    vector<int> dp(x+1, x+1); dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            dp[i] = min(dp[i], dp[i-values[j]]+1);
        }
    }
    cout << dp[x] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> x >> n;
    for (int i = 0; i < n; i++) { cin >> values[i]; }
    solve();
    return 0;
}