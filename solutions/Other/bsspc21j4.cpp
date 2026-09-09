#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5+5;
int X, N, ans; vector<int> arr[MM]; priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> X >> N;
    
    for (int i = 0; i < N; i++) {
        int t, f; cin >> t >> f;
        if (t-X < 0) t = 0; else t = t-X;
        if (MM > t) arr[t].push_back(f);
    }
    for (int i = 0; i < MM; i++) {
        for (auto u : arr[i]) pq.push(u);
        while (!pq.empty() && (pq.top() < i)) pq.pop();
        if (!pq.empty()) { pq.pop(); ans++; }
    }
    cout << ans << '\n';
    return 0;
}