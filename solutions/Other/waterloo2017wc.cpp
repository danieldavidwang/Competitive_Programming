#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e2+2;
int n, k, cnt, curr, t;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    vector<int> ans(n);
    if (n > 2*k) { cout << "0\n"; return 0; }
    for (int i = 0; i < k; i++) {
        t = 0, curr = 0;
        for (int j = i; j < n; j += k) t++;
        for (int j = i; j < n; j += k) ans[j] = (t-curr) + cnt, curr++;
        cnt += curr;
    }
    for (auto &a: ans) cout << a << " ";
    cout << '\n'; return 0;
}