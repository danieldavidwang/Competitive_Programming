#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int MM = 250005;
bitset<MM> sieved;
vector<int> primes;
vector<int> psa;

void sieve() {
    sieved[0] = true;
    sieved[1] = true;
    for (int p = 2; p < MM; p++) {
        if (!sieved[p]) {
            primes.push_back(p);
            for (int i = p * 2; i < MM; i += p) sieved[i] = true;
        }
    }
}

void comp_psa() {
    psa.resize(MM);
    for (int i = 1; i < MM; i++) {
        psa[i] = psa[i-1] + (sieved[i] ? 0 : i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    sieve();
    comp_psa();

    int Q;
    cin >> Q;
    while (Q--) {
        int x, k;
        cin >> x >> k;

        auto it = lower_bound(primes.begin(), primes.end(), x);
        int idx = distance(primes.begin(), it);

        if (!sieved[primes[idx]]) k--;

        int temp = primes[idx + k];
        int result = psa[temp] - psa[x] + (sieved[x] ? 0 : x);
        cout << temp << ' ' << result << '\n';
    }

    return 0;
}