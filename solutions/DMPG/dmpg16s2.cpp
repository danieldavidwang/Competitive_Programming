#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
long d, k, n, ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cin >> n >> k >> d;
    for (int i = 0; i < d; i++) { ans += (n%k); n /= k; }
    ans += n; cout << ans << '\n';
}