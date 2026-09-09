#pragma GCC optimize (2)
#include <bits/stdc++.h>
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
char op; ll a, b, n, m, v[MM], bit[MM], leq[MM];

void updateBIT(ll idx, ll value) { while (idx <= n) { bit[idx] += value; idx += idx & (-idx); } }

ll sumBIT(ll idx) {
    ll sum = 0;
    while (idx > 0) { sum += bit[idx]; idx -= idx&(-idx); }
    return sum;
}

void updateLEQ(ll idx, ll pm) { while(idx <= MM) { leq[idx] += pm; idx += idx&(-idx); } }

ll sumLEQ(ll idx) {
    ll sum = 0;
    while (idx > 0) { sum += leq[idx]; idx -= idx&(-idx); }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    mem(v, 0); mem(bit, 0); mem(leq, 0);

    for (ll i = 1; i <= n; i++) {
        cin >> v[i];
        updateBIT(i, v[i]);
        updateLEQ(v[i], 1);
    }

    for (int i = 0; i < m; i++) {
        cin >> op;
        if (op == 'C') {
            cin >> a >> b;
            updateLEQ(v[a], -1);
            updateBIT(a, -v[a]);
            v[a] = b;
            updateLEQ(b, 1);
            updateBIT(a, b);
        }
        else if (op == 'S') {
            cin >> a >> b;
            cout << sumBIT(b) - sumBIT(a-1) << '\n';
        }
        else if (op == 'Q') {
            cin >> a;
            cout << sumLEQ(a) << '\n';
        }
    }
    return 0;
}