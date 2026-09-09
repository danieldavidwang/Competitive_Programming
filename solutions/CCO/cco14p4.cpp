#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v;
int n, s, in = 0, ans = 1;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        if (s == i) {
            in = x;
            continue;
        }
        if (x >= y) v.push_back(make_pair(y, x-y));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        if (in < v[i].first) break;
        ans++;
        in += v[i].second;
    }
    cout << in << '\n' << ans << '\n';
}