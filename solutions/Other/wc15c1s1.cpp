#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int n, pos, ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        pos += y;
        if (pos-x) { ans += (pos-x); pos = x; }
    }
    cout << ans << '\n';
}