#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef long ll;
const ll MOD = 998244353;
int n, k;
ll ans, cntw, cnta, cntc;
string s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k >> s;
    ll cntw2 = 0, cntc_all = 0, cntc_a = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') cnta++, cntw2 += cntw;
        else if (s[i] == 'C') cntc_all += cntw2, cntc++, cntc_a += cnta;
        else if (s[i] == 'W') cntw++;
    }
    for (int i = 0; i < k; i++) {
        ans += cntc_all;
        // ans %= MOD;
        ans += (cntw*i%MOD)*cntc_a % MOD;
        ans %= MOD;
        ans += (cntw2*i%MOD)*cntc % MOD;
        // ans %= MOD;
        ans += cntw*(i * (ll) (i-1)/2) % MOD * cnta % MOD * cntc % MOD;
        ans %= MOD;
    }
    cout << ans << '\n'; return 0;
}