#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
int N, a, b;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N; vector<pair<int, int>> V;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        V.push_back(make_pair(a, b));
    }
    sort(V.begin(), V.end());
    set<int, greater<int>> S;
    for (int i = 0; i < (N); i++) {
        int x = V[i].second;
        auto it = S.upper_bound(x);
        if (it != S.end()) S.erase(it);
        S.insert(x);
    }
    cout << (S.size()) << '\n';
    return 0;
}