#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, c, ans;
const ll MAX_N = 1e4+1;
vector<ll> primes;

void segSieve() {
    int n = MAX_N; vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) if (isPrime[i]) for (int j = i * i; j <= n; j += i) isPrime[j] = false;
    for (int i = 2; i <= n; i++) if (isPrime[i]) primes.push_back(i);
}

ll cnt(ll n) {
    ll count = 1;

    for (ll prime : primes) {
        if (prime * prime > n) break;

        if (n % prime == 0) {
            ll fact = 0;
            while (n % prime == 0) {
                n /= prime;
                fact++;
            }
            count *= (2 * fact + 1);  // factors of p^a is (a+1)
        }
    }

    if (n > 1) count *= 3;  // remaining prime factor has exponent 1, so count of factors is 2 * 1 + 1 = 3
    return count;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    segSieve();
    cin >> t;
    
    while (t--) {
        cin >> c;
        ans = cnt(c);
        cout << ans << '\n';
    }

    return 0;
}