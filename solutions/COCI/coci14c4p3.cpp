#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; ll arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        ans += arr[i];
        if (m < arr[i]) m = arr[i];
    }
    (ans/2 + 1 > m) ? cout << ans : cout << 2*m; cout << '\n';
    return 0;
}