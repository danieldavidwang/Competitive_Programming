#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
typedef pair<int, int> pi;
int N, M, T, ans, sum; vector<pi> a; pi x;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> T;
    for(int i=0, p, c; i<N; i++) {
        cin >> p >> c;
        x.first = p; x.second = c;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    priority_queue<int, vector<int>, greater<int> > pq;
    for (pi e : a) {
        int p = e.first;
        int c = e.second;
        if (p*2 + T > M) break;
        sum += c; pq.push(c);
        int k = (M - 2*p)/T;
        while (pq.size() > k) {
            sum -= pq.top();
            pq.pop();
        }
        ans = max(ans, sum);
    }
    cout << ans << '\n';
}