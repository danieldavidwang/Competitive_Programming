#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int n; ll a, b, c, d, e;

ll func(int i) {
    if (i == 0) return e;
    else return ((func(i/b)*a) % MOD + (func(i/d)*c) % MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> a >> b >> c >> d >> e >> n;
    cout << func(n) << '\n';
    return 0;
}