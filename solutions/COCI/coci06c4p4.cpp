#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, c; cin >> n >> c;
    vector<vector<long long>> dp(2, vector<long long>(c + 2));
    for (int x = 0; x <= c + 1; x++) dp[1][x] = 1;

    for (int x = 2; x <= n; x++) {
        dp[x & 1][0] = 1;
        for (int y = 1; y <= c; y++) {
            long long withoutSubtraction = (dp[(x & 1) ^ 1][y] + MOD) % MOD;
            long long subtractionTerm = (y - x >= 0) ? dp[(x & 1) ^ 1][y - x] : 0;
            long long withSubtraction = (withoutSubtraction - subtractionTerm + MOD) % MOD;
            dp[x & 1][y] = (withSubtraction + dp[x & 1][y - 1]) % MOD;
        }
    }

    cout << (dp[n & 1][c] - dp[n & 1][c - 1] + MOD) % MOD << '\n';
    return 0;
}