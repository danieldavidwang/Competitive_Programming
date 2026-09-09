#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
typedef unsigned long long ll;

ll mod_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result*base) % mod;
        exp >>= 1;
        base = (base*base) % mod;
    }
    return result;
}

ll choose(ll n, ll m) {
    ll res = 1;
    for (int i = 1; i <= n; i++) {
        res *= (m-n+i);
        res %= MOD;
        res *= mod_pow(i, MOD-2, MOD);  // Using modular inverse to divide
        res %= MOD;
    }
    return res;
}

int main() {
    ll n; scanf("%lld", &n);
    cout << (choose(n+1, 2*n+2)-1) << '\n';
    return 0;
}