#pragma GCC optimize (2)
#include <bits/stdc++.h>
#define FOR(i, x, y) for (int i = x; i < y; i++)
using namespace std;
const int MM = 2e3+3;
int ans, x, n, m, r[MM], w[MM], curr[MM]; queue<int> q; priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) { cin >> r[i]; pq.push(-i); }
    for (int i = 1; i < m+1; i++) cin >> w[i];

    for (int i = 0; i < m*2; i++) {
        cin >> x;
        if (x > -1) q.push(x);
        else pq.push(-curr[-x]);

        while (q.size() && pq.size()) {
            curr[q.front()] = -pq.top();
            ans += r[-pq.top()] * w[q.front()]; q.pop(); pq.pop(); 
        }
    }
    cout << ans << '\n';
}