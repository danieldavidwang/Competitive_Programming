#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef long ll;
typedef pair<ll, ll> pll;
ll ans, h, n; stack<pll> s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    while (n--) {
        cin >> h;
        pll t = pll(h, 1);
        while (!(s.empty()) && s.top().first <= h) {
            ans += s.top().second;
            if (h == s.top().first) t.second += s.top().second;
            s.pop();
        }
        if (!(s.empty())) ans++;
        s.push(t);
    }
    cout << ans << '\n';
}