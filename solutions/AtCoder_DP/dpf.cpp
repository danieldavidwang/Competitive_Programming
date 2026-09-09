#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4+4;
int cnt, m, n, dp[MAXN][MAXN];
string t, s, ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> s >> t;
    m = s.length(); n = t.length();
    
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = s[i-1] == t[j-1] ? dp[i-1][j-1]+1 : max(dp[i-1][j], dp[i][j-1]);
        
    cnt = dp[m][n];
    
    while (cnt) {
        if (dp[m][n] == dp[m-1][n]+1 && dp[m][n] == dp[m][n-1]+1) {
            ans = s[m-1] + ans; cnt--;
            if (m > 1) m--;
            else n--;
        } else if (dp[m][n] == dp[m-1][n] && dp[m][n] == dp[m][n-1]+1) m--;
        else n--;
    }
    cout << ans << '\n';
}