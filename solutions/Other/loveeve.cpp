#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int N, ans; vector<int> v;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    N *= 2;
    for (int i = 0, x; i < N; ++i) { cin >> x; v.push_back(x); }
    sort(v.begin(), v.end());
    for (int i = 0; i < N/2; ++i) ans -= v[i];
    for (int i = N/2; i < N; ++i) ans += v[i];
    cout << ans << '\n';
}