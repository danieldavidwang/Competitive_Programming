#include <bits/stdc++.h>
using namespace std;
int r, ans;

int cnt(int x) {
    int count = 0;
    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) count++;
    }
    return count;
}

void solve() {
    for (int j = 1; j <= r; j++) {
        ans += cnt(j);
    }
    cout << ans << '\n';
}

int main() {
    for (int i = 0; i < 5; i++) {
        cin >> r; ans = 0;
        solve();
    }
    return 0;
}