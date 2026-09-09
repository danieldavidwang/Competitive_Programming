#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int N, a1[MM], a2[MM], curr = 1; map<int, vector<int> > cnt;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N; for (int i = 1; i <= N; i++) cin >> a1[i];

    for (auto i = 1; i <= N; i++) {
        int dif = a1[i] - a1[i-1];
        if (dif > 1) { cout << "-1\n"; return 0; }
        if (dif < 0) { cout << "-1\n"; return 0; }
        else cnt[a1[i]].push_back(i);
    }

    for (auto [k, i]: cnt) {
        int x = curr-1 + i.size();
        curr = x+1;
        for (int y: i) a2[y] = x--;
    }

    for (int i = 1; i <= N; i++) cout << a2[i] << " ";
    cout << '\n'; return 0;
}