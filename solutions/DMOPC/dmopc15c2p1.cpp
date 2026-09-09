#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int n, k, ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k;
    while (n >= k) {
        ans += k;
        n -= (k-1);
    }
    cout << (ans+n) << '\n';
    return 0;
}