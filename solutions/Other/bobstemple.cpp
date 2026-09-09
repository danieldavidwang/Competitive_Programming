#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    for (int i = 0; i < N; i++) { int x; cin >> x; mp[x]++; }
    for (auto u : mp) cout << u.first << ' ';
    for (auto itr = mp.rbegin(); itr != mp.rend(); itr++) {
        int c = (*itr).second;
        c -= 1;
        while (c--) cout << (*itr).first << ' ';
    }
    return 0;
}