#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 5e4+5;
int n; long long ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; vector<long long> v1(n), v2(n);
    for (auto &a: v1) cin >> a;
    for (auto &a: v2) cin >> a;
    sort(v1.begin(), v1.end()); sort(v2.rbegin(), v2.rend());
    for (int i = 0; i < n; i++) ans += (v1[i]*v2[i]);
    cout << ans << '\n'; return 0;
}