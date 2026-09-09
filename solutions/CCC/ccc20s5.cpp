#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+6;
int n, a[MM], cnt[MM]; double out = 0.5, dp[MM];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) { cin >> a[i]; }
    if (a[n] == a[1]) { cout << "1\n"; return 0; }
    dp[a[1]] = 1; cnt[a[1]]++; dp[a[n]] = 0; cnt[a[n]]++;
    for (int i = n-1; i > 1; i--) {
        if (!(cnt[a[i]])) dp[a[i]] = out;
        out *= (n-i+1); out += dp[a[i]]; out /= (n-i+2);
        cnt[a[i]] += 1;
    }
    out = 0;
    for (int i = 1; i <= n; i++) out += cnt[i] * dp[i] / n;
    printf("%.10f", out);
}