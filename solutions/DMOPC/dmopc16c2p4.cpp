#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, counter;

ll solve(ll n) {
    counter = 0;
    for (ll i = 5; n/i >= 1; i *= 5) counter += (n/i);
    return counter;
}

ll most(ll m) {
    if (m < 0) return 1;
    ll mid, left = 0, right = LONG_MAX;
    while (left < right) {
        mid = (left+right) / 2;
        if (solve(mid)-m > 0) right = mid;
        else left = mid+1;
    }
    return left;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b; cout << most(b) - most(a-1) << '\n';
    return 0;
}