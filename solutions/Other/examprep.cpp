#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+6;
int n, q, p[MM], s[MM];
ll val[MM];
int find(int d) { return d==p[d]? p[d]: p[d]=find(p[d]); }

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) { p[i] = i;  s[i] = 1;  cin >> val[i]; }
    for(int i = 1, op, x, y; i <= q; i++) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            int fx = find(x), fy = find(y);
            if (fx != fy) { p[fx] = fy; s[fy] += s[fx]; val[fy] += val[fx]; }
        }
        else if (op == 2) { cin >> x; cout << s[find(x)] << "\n"; }
        else { cin >> x; cout << val[find(x)] << "\n"; }
    }
    return 0;
}