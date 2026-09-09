#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MM = 1e6+5;
ll n, k, ans; vector<ll> v(MM), psa(MM);

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (ll i = 1; i <= n; i++) {
        cin >> v[i];
        psa[i] = (v[i]^psa[i-1]);
    }
    for (ll i = k; i <= 1000; i *= k) {
        vector<int> freq(MM); freq[0] = 1;
        for (ll y = 1; y <= n; y++) {
            ans += freq[psa[y]^i];
            freq[psa[y]]++;
        }
    }
    cout << ans << '\n';
}