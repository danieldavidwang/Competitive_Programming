#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int n, x, y, ans; set<pair<int,int>> s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    while (n--) {
        cin >> x >> y;
        s.insert({x, y});
    }
    for (auto &i: s)
        for (auto &j: s)
            if (s.count({i.first, j.second}) && s.count({j.first, i.second})) ans = max((abs(i.first-j.first) * abs(i.second-j.second)), ans);
    cout << ans << '\n'; return 0;
}