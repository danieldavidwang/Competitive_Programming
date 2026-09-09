#pragma GCC optimize (2)
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n, m, k, i, f;
ll calc(ll a) { return a*(a+3)/2; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    k += 1;
    if (k >= m+n-2) { cout << "-1\n"; return 0; }
    i = min(2*min(n, m) - 2, k), f = max(k - i, (ll) 0);
    cout << calc(i/2) + calc((i+1)/2) + f*min(n, m) << '\n';
    return 0;
}