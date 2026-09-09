#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int n, dp[MM][3];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    vector<pair<int,int>> v(n);
    cin >> v[0].first >> v[0].second;
    dp[0][0] = 2*v[0].second-v[0].first-1; dp[0][1] = v[0].second-1;
    for (int x = 1; x < n; x++) {
        cin >> v[x].first >> v[x].second;
        dp[x][0] = min(dp[x-1][0] + abs(v[x-1].first-v[x].second) + v[x].second - v[x].first, dp[x-1][1] + abs(v[x-1].second-v[x].second) + v[x].second - v[x].first);
        dp[x][1] = min(dp[x-1][0] + abs(v[x-1].first-v[x].first) + v[x].second - v[x].first, dp[x-1][1] + abs(v[x-1].second-v[x].first) + v[x].second - v[x].first);
    }
    cout << dp[n-1][1]+n-v[n-1].second+n-1 << '\n';
    return 0;
}