#include <bits/stdc++.h>
using namespace std;

int cnt(int n) {
    int ret = 0;
    for (int i = 1, end = static_cast<int>(std::sqrt(n)); i <= end; i++) if (n % i == 0) ret++;
    return ret;
}

int main() {
    for (int t = 0; t < 5; t++) {
        int n; cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i++) ans += cnt(i);
        cout << ans << '\n';
    }
    return 0;
}