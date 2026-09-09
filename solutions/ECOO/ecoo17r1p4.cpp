#include <bits/stdc++.h>
using namespace std;
int N, cnt = 0, ans = INT_MAX;

int swap(vector<string> list) {
    vector< pair<string, int> > k(list.size());
    for (int i = 0; i < list.size(); i++) {
        k[i].first = list[i];
        k[i].second = i;
    }
    sort(k.begin(), k.end());
    
    vector<bool> sorted(list.size(), false);
    int s = 0;
    for (int i = 0; i < list.size(); i++) {
        if (sorted[i] || k[i].second == i) continue;
        int cycle = 0, start = i;
        while (!sorted[start]) {
            sorted[start] = true; start = k[start].second;
            cycle++;
        }
        s += cycle - 1;
    }
    return s;
}

int main() {
    while (cnt < 10) {
        cin >> N;
        vector<string> names(N);
        for (int i = 0; i < N; i++) cin >> names[i];
        ans = INT_MAX;
        for (int i = 0; i < N; i++) {
            vector<string> rem = names;
            rem.erase(rem.begin() + i);
            ans = min(ans, swap(rem));
        }
        cout << ans << '\n';
        cnt++;
    }
}