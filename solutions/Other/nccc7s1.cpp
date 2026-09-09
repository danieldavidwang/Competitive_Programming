#include <bits/stdc++.h>
#include <utility>
using namespace std;
using ll = unsigned long long; using p = pair<ll, ll>;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll x, y, re;
    cin >> x >> y;
    re = x * y;
    if (!(re%2)) printf("%lld.0\n", re/2);
    else printf("%lld.5\n", re/2);
    return 0;
}