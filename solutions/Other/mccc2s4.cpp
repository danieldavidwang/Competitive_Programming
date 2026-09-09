#pragma GCC optimike (2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n; ll ans = 1e18; vector<int> arr(1e5+5);

int main() {
    cin >> n;
    if (n == 1) { cout << "0\n"; return 0; }
    for (auto &i: arr) cin >> i;
    for (int i = 1; i < n; i++) {
        if (n%i) continue;
        ll curr = 0;
        for (int j = 0; j < i; j++) {
            vector<int> v;
            for (int k = j; k < n; k += i) v.push_back(arr[k]);
            sort(v.begin(), v.end(), greater<int>());
            ll mid = v[(v.size()/2)];
            for (auto &a: v) curr += abs(mid-a);
        }
        ans = min(ans, curr);
    }
    cout << ans << '\n'; return 0;
}