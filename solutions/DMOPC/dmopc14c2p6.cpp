#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;

struct Fenwicks {
    int n;
    vector<int> fenw;
    Fenwicks(int n): n(n), fenw(n+1, 0) {}
    void update(int i, int val) {
        for (; i <= n; i += i & (-i)) {
            fenw[i] += val;
        }
    }
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & (-i)) {
            sum += fenw[i];
        }
        return sum;
    }
    int rangeQuery(int l, int r) {
        return query(r) - query(l-1);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;
    vector<int> mass(N);
    for (int i = 0; i < N; i++) cin >> mass[i];

    vector<pair<int,int>> trees(N);
    for (int i = 0; i < N; i++) trees[i] = {mass[i], i};
    sort(trees.begin(), trees.end(), [](auto &a, auto &b) { return a.first > b.first; });

    int Q; cin >> Q;
    struct Query { int a, b, q, idx; };
    vector<Query> queries(Q);
    for (int i = 0; i < Q; i++) { cin >> queries[i].a >> queries[i].b >> queries[i].q; queries[i].idx = i; }

    sort(queries.begin(), queries.end(), [](auto &A, auto &B) { return A.q > B.q; });

    Fenwicks fenw(N);
    vector<int> ans(Q);
    int tree_idx = 0;

    for (auto &qr : queries) {
        int Qq = qr.q;
        while (tree_idx < N && trees[tree_idx].first >= Qq) {
            fenw.update(trees[tree_idx].second + 1, trees[tree_idx].first);
            tree_idx++;
        }
        ans[qr.idx] = fenw.rangeQuery(qr.a+1, qr.b+1);
    }

    for (int x : ans) cout << x << "\n";
    return 0;
}