#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int n, d = 0;
vector<int> c, m;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i = 0, x; i < n; i++) { cin >> x; c.push_back(x); }
    for (int i = 0, x; i < n; i++) { cin >> x; m.push_back(x); }
    sort(m.begin(), m.end()); sort(c.begin(), c.end());
    for (int i = 0; i < n; i++) d = max(abs(m[i]-c[i]), d);
    cout << d << '\n';
}