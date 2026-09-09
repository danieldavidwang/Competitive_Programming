#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const long long MM = 1e6+6;
long long N, Q, H, a[MM], best = 0;

void psa() {
    for (int i = 1; i <= N; i++) { a[i] += a[i-1]; }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> Q >> H;
    for (int i = 1, x, y; i <= N; i++) {
        cin >> x >> y;
        if (x > H) a[i] = 0;
        else a[i] = y;
    }
    psa();
    for (int i = 1, r, l; i <= Q; i++) {
        cin >> r >> l;
        long long temp = a[l] - a[r-1];
        if (temp > best) best = temp;
    }
    cout << best << '\n';
}