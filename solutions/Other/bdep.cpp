#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p, y, t;
bool check(ll x) {
    ll amount = 0;
    for(int i=1; i<=y; i++){
        amount += x;
        amount += amount*p/100;
        if (amount >= t) return true;
    }
    return false;
}

int main() {
    cin >> p >> y >> t;
    ll lo = 1, hi = t, ans = 0;
    while (lo <= hi) {
        ll mid = (lo + hi)/2;
        if(check(mid)) { ans = mid; hi = mid - 1; }
        else lo = mid + 1;
    }
    cout << ans << '\n';
}