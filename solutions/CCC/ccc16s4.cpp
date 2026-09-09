#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 4e2+2;
int N, psa[MM], ans, dp[MM][MM];
int rangeSum(int x, int y) { return psa[y] - psa[x-1]; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> psa[i];
        ans = max(ans, psa[i]);
        dp[i][i] = 1;
        psa[i] += psa[i-1];
    }
    
    for (int i = 1; i < N; i++) {
        for (int j = 1, r = j + i; r <= N; j++, r++) {
            for (int p = j, q = r; p+1 <= q;) {
                if (dp[j][p] && dp[q][r] && (dp[p+1][q-1] || p+1 == q) && rangeSum(j, p) == rangeSum(q, r)) { dp[j][r] = 1; break; }
                if (rangeSum(j, p) < rangeSum(q, r)) p++;
                else q--;
            }
            if (dp[j][r]) ans = max(rangeSum(j, r), ans);
        }
    }
    
    cout << ans << '\n';
    return 0;
}