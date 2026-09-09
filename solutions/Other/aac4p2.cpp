#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5, sz2 = 1e9+9;
int n, q, maxi; ll a[sz], plcm[sz];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    plcm[1] = a[1]; maxi = n;
    for (int i = 2; i <= n; i++) {
        plcm[i] = lcm(plcm[i-1], a[i]);
        maxi = i;
        if (plcm[i] > 1e9) break;
    }
    for (int i = 0, t; i < q; i++) {
        int l = 1, r = min(n, maxi+1), ans = -1;
        cin >> t;
        if(!t) { cout << -1 << "\n"; continue; }
        while (l <= r) {
            int mid = (l+r)/2;
            if (t % plcm[mid] != 0) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        cout << ans << "\n";
    }
}