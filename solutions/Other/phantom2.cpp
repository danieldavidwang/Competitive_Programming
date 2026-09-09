#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+6;
bool sieved[MM]; int n, a, b, ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    while (n--) {
        memset(sieved, 0, sizeof(sieved)); ans = 0;
        cin >> a >> b;
        for (int i = 2; i < b; i++) {
            if (!sieved[i]) {
                if (i >= a) ans++;
                if (b >= i*i) for (int j = i*2; j < b; j += i) sieved[j] = 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}