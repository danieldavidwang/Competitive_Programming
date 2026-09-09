#include <bits/stdc++.h>
using namespace std;
int m, n;
vector<int> values;

void solve(int x) {
    vector<int> dp(x+1, x+1); dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= values[j]) { dp[i] = min(dp[i], dp[i-values[j]]+1); }
        }
    }
    cout << dp[x] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 5; i++) {
        cin >> m >> n; values.clear();
        for (int j = 0, c; j < n; j++) {
            cin >> c; values.push_back(c);
        }
        solve(m);
    }
    return 0;
}