#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int a, b, cnt, ans, N, k; pair<int, int> arr[MM]; priority_queue<int, vector<int>, greater<int> > q;
bool order(pair<int, int> p1, pair<int, int> p2) { if (p1.first == p2.first) return p1.second < p2.second; return p1.first > p2.first; }

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a >> b;
        if (!a || !b) cnt++;
        else arr[++k] = {a, b};
    }
    sort(arr+1, arr+k+1, order);

    for (int i = 1; i <= k; i++) {
        q.push(arr[i].second);
        if (cnt+k-i < arr[i].first) {
            ans += q.top();
            q.pop();
            cnt++;
        }
    }
    cout << ans << '\n';
}