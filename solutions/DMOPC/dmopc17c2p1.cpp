#include <bits/stdc++.h>
using namespace std;
long long N, c, v, ans = 0;

int main() {
    cin >> N;
    for (long long i = 1, c, v; i <= N; i++) {
        cin >> c >> v;
        if (v > 0) {
            ans += c;
        }
    }
    cout << ans << '\n';
}