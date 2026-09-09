#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int n, m, h, d, ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> h; vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = n-2; i > -1; i--) {
        d = v[i+1] - v[i] - h;
        if (d > 0) {
            ans += ((d+m-1) / m);
            v[i] += (int) ((d+m-1) / m) * m;
        }
    }
    cout << ans << '\n'; return 0;
}