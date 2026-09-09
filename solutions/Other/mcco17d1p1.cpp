#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define eb emplace_back
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int MN = 2e5+5;
int N, a[MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    priority_queue<int, vector<int>, greater<>> q;
    int pos = -1, sum = 0, lst = -1, cnt = 0;
    while (sum < N - 1 && pos < N) {
        while (pos < sum) q.push(a[++pos]);
        while (!q.empty() && q.top() <= lst) q.pop();
        if (q.empty()) break;
        sum += (lst = q.top()); q.pop();
        cnt++;
    }
    if (sum < N-1) cnt = -1;
    cout << cnt << '\n';
    return 0;
}