#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> data(N);
    for (int i = 0; i < N; i++) cin >> data[i];

    // build iterative segment tree with: Tree size = 2*N, leaves at indices [N, 2*N-1], internal nodes at [1, N-1].
    vector<int> segtree(2*N, INT32_MAX);

    // init leaves
    for (int i = 0; i < N; i++) segtree[N+i] = data[i];
    // build internal nodes
    for (int i = N-1; i >= 1; i--) segtree[i] = min(segtree[2*i], segtree[2*i+1]);

    auto update = [&](int idx, int val) {
        // update value at pos idx
        idx += N;
        segtree[idx] = val;
        for (idx /= 2; idx >= 1; idx /= 2) {
            segtree[idx] = min(segtree[2*idx], segtree[2*idx+1]);
        }
    };

    auto query = [&](int l, int r) {
        // query min on interval [l, r]
        int res = INT32_MAX;
        l += N; r += N;
        while (l <= r) {
            if ((l & 1) == 1) {
                res = min(res, segtree[l]);
                l++;
            }
            if ((r & 1) == 0) {
                res = min(res, segtree[r]);
                r--;
            }
            l /= 2; r /= 2;
        }
        return res;
    };

    for (int i = 0; i < M; i++) {
        char op;
        cin >> op;
        if (op == 'Q') {
            int a, b; cin >> a >> b;
            cout << query(a, b) << "\n";
        } else if (op == 'M') {
            int idx, val; cin >> idx >> val;
            update(idx, val);
        }
    }

    return 0;
}