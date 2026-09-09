#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int k, x;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> k;
    vector<pair<int, int>> v;
    while (k) {
        int n = 1;
        while (k >= (n) * (n+1) / 2) n++;
        v.emplace_back(x+n, x+1);
        for (int i = x+1; i < x+n; i++) v.emplace_back(i, i+1);
        if (x != 0) v.emplace_back(1, x+1);
        k -= n * (n-1) / 2; x += n;
    }
    cout << x << " " << v.size() << '\n';
    for(auto &i : v) cout << i.first << " " << i.second << '\n';
}