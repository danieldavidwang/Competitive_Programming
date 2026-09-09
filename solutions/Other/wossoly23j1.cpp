#include <bits/stdc++.h>
using namespace std;
int ans = 1e9+9, x;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    while (n--) {
        cin >> x; if (ans > x) ans = x;
    }
    cout << ans << '\n';
}