#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
unordered_map<int, bool> r, c;
unordered_map<int, unordered_map<int, bool> > ind;
int N, Q, a, i, j;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> Q;

    while (Q--) {
        cin >> a >> i >> j;

        if (a == 1) {
            ind[i][j] = !ind[i][j];
            r[i] = !r[i];
            c[j] = !c[j];
        } else {
            int st = ind[i][j] + r[i] + c[j];
            st %= 2;
            cout << st << '\n';
        }
    }
    return 0;
}