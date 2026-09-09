#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int n, x, a, b; long ans; priority_queue<int, vector<int>, greater<int> > q;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    while (n--) { cin >> x; q.push(x); }
    while (1 < q.size()) {
        a = q.top(); q.pop();
        b = q.top(); q.pop();
        ans += (a+b);
        q.push(a+b);
    }
    cout << ans << '\n'; return 0;
}