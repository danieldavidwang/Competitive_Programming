#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n; ll x, y, d, ans;

ll getGCD(ll a, ll b) {
    if (a == 0) return b;
    return getGCD(b%a, a);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; vector<pair<ll, ll>> v(n);
    for (auto &i: v) cin >> i.first >> i.second;
    ans = (ll) n*(n-1)*(n-2) / 6;
    sort(v.begin(), v.end());
    
    for (int i = 0; i < n; i++) {
        map<pair<ll,ll>, ll> mp;
        for (int j = i+1; j < n; j++) {
            x = (v[i].first-v[j].first);
            y = (v[i].second-v[j].second);
            d = abs(getGCD(x, y));
            x /= d; y /= d;
            if (x >= 0) x *= -1, y *= -1;
            ll &curr = mp[{x, y}];
            ans -= curr; curr++;
        }
    }
    cout << ans << '\n'; return 0;
}