#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MM = 1e7+7;
ll cnt, L = 1, R = 1, n, m, res[MM][3];
double l, r;

ll gcd(ll a, ll b) {
    if (a == 0) return b;
    return gcd(b%a, a);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    ll a = n / gcd(n, m), b = m / gcd(n, m);
    double ab = double(b) / double(a);
    
    for (ll i = 1; i <= a; i++) {
        L = R; l = r; 
        r += ab-(ll)(ab); R += (ll)(r);
        r = (r-(ll)(r)); R += (ll)(ab);
        res[i][0] = L; res[i][1] = R+1;
        if (i == a) res[i][1] = b+1;
        cnt += res[i][1]-res[i][0];
    }
    cnt *= gcd(n,m); cout << cnt << '\n';
    for (ll i = 1; i <= n; i++) {
        ll k = (i-1) / a;
        for (ll j = res[i-k*a][0]; j < res[i-k*a][1]; j++) cout << i << " " << j + k*b << '\n';
    }
}