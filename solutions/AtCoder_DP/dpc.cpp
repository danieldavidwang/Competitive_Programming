#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int n, in[3][MM], dp[3][MM];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> in[0][i] >> in[1][i] >> in[2][i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
      	        if (j != k) dp[k][i+1] = max(dp[k][i+1], dp[j][i]+in[k][i+1]);
    
    cout << max(dp[0][n], max(dp[1][n], dp[2][n])) << '\n'; return 0;
}