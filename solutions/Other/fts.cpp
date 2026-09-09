#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+6;
int n, ans, g[MM]; char c[MM];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) {
        if (c[i] == '1') {
            g[i] ^= 1;
            g[i+1] ^= 1;
        }
    }
    for (int i = 1; i <= n; i++) ans += g[i];
    cout << ans << '\n';
}