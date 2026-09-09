#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5+5;
int ans, cur, n, k, a[MM]; queue<int> q;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 1; i < k+1; i++) if (a[i]) q.push(i);
    while (!q.empty()) {
        cur = q.back();
        while (!q.empty()) q.pop();
        for (int i = cur+1; i < min(n, cur+k+1); i++) if (a[i]) q.push(i);
        ans++;
    }
    if (cur != n-1) cout << "-1\n";
    else cout << ans << '\n';
    return 0;
}