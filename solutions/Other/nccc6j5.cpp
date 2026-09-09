#pragma GCC optimize (2)
#include <iostream>
#include <vector>
using namespace std;
const long long MOD = 998244353; const int MM = 1e3+3;
long long dp[MM][MM], arr[MM];
int n, k;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int x = 0, a; x < n; x++) { cin >> a; arr[a]++; }
    for (int x = 0; x <= n; x++) dp[0][x] = 1;
    for (int x = 1; x <= k; x++) for (int y = x; y <= n; y++) dp[x][y] = (dp[x][y-1] + arr[y] * dp[x-1][y-1]) % MOD;
    cout << dp[k][n] << '\n'; return 0;
}