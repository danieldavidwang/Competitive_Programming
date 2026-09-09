#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
// const int MM = 1e6+6;
int n, m, k, low, high, mid;
vector<int> c, t;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0, x; i < n; i++) { cin >> x; c.push_back(x); }
    for (int i = 0, x; i < m; i++) { cin >> x; t.push_back(x); }
    sort(c.begin(), c.end(), greater<int>());
    sort(t.begin(), t.end(), greater<int>());
    low = 1, high = n+1;
    while (low < high) {
        mid = (low + high)/2;
        int j = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            while (cnt == mid || (j < m) && (t[j] < c[i]-k) || (t[j] > c[i])) { j++; cnt = 0; }
            if (j < m) cnt++;
        }
        if (j < m) high = mid;
        else low = mid+1;
    }
    if (low == n+1) cout << "-1\n";
    else cout << low << '\n';
}