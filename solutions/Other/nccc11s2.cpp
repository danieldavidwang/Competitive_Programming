#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long N;
long long ans = 1;

void solve(long long x) {
    for (long long i = 1; i <= x; i++) {
        ans *= i;
        ans %= MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    solve(N);
    cout << ans << '\n';
}