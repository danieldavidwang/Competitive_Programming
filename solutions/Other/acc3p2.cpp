#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n; ll a, b, curr, ans = LONG_MAX;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    vector<pair<ll, ll>> pos(n);
    vector<ll> v1(n), v2(n);
    for (int i = 0; i < n; i++) {
        cin >> pos[i].first >> pos[i].second;
        v1[i] = pos[i].first - pos[i].second;
        v2[i] = pos[i].first + pos[i].second;
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    a = v1[n/2], b = v2[n/2];
    ll X = (a+b)/2, Y = (b-a)/2;

    for (ll i = X-1; i < X+1; i++) {
        for (ll y = Y-1; y < Y+1; y++) {
            curr = 0;
            for (auto &a: pos) curr += max(abs(i-a.first), abs(y-a.second));
            ans = min(curr, ans);
        }
    }
    cout << ans << '\n';
    return 0;
}