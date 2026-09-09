#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double d;
d dis(ll x1, ll y1, ll x2, ll y2) { return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)); }
ll n;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;

    while (n--) {
        ll x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        d d1 = dis(x1, y1, x2, y2);
        d d2 = dis(x2, y2, x3, y3);
        d d3 = dis(x3, y3, x1, y1);
        d perimeter = d1 + d2 + d3;
        d semi = perimeter / 2;
        cout << fixed << setprecision(5) << sqrt(semi * (semi - d1) * (semi - d2) * (semi - d3)) << " " << perimeter << '\n';
    }
    return 0;
}