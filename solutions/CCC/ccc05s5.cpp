#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
private:
    vector<int> tree;

public:
    FenwickTree(int size) : tree(size + 1) {}

    void update(int idx, int delta) {
        for (; idx < tree.size(); idx += idx & -idx)
            tree[idx] += delta;
    }

    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += tree[idx];
        return sum;
    }
};

int main() {
    int t;
    cin >> t;

    vector<int> a(t);
    vector<int> sorted_a;
    map<int, int> rank;

    for (int i = 0; i < t; ++i) {
        cin >> a[i];
        sorted_a.push_back(a[i]);
    }

    sort(sorted_a.begin(), sorted_a.end());
    sorted_a.erase(unique(sorted_a.begin(), sorted_a.end()), sorted_a.end());

    int rank_idx = 1;
    for (int num : sorted_a)
        rank[num] = rank_idx++;

    FenwickTree fenwick(rank.size());

    long double inversions = 0;
    for (int i = 0; i < t; ++i) {
        int r = rank[a[i]];
        inversions += i - fenwick.query(r);
        fenwick.update(r, 1);
    }

    long double average_inversions = inversions / t;
    cout << fixed << setprecision(2) << (average_inversions+1) << '\n';
    return 0;
}