#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    long long n, m, a, b, c;
    cin >> n >> m; cin >> a >> b >> c;
    vector<long long> arr(n); vector<long long> psa(n);
    
    for (auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    psa[0] = (arr[0] - 1) * b;

    for (int x = 1; x < n; x++) psa[x] = psa[x - 1] + (arr[x] - 1) * b;

    long long mi = psa[n - 1], curV = 0;

    for (int x = n - 1; x >= 0; x--) {
        curV += (arr[x] - 1) * a + c * (n - x - 1);
        mi = min(mi, (x ? psa[x - 1] : 0) + curV);
    }

    cout << mi << '\n';
    return 0;
}