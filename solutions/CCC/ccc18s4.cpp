#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n; unordered_map<int, ll> dp;

ll solve(int x) {
    if (x == 1) return 1;
    if (dp[x]) return dp[x];
    for (int i = x; i >= 2;) {
        int curr = x/i, n = x/(curr+1);
        dp[x] += (ll) (i-n) * solve(curr);
        i = n;
    }
    return dp[x];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; cout << solve(n) << '\n';
    return 0;
}