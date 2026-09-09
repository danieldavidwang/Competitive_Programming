#pragma GCC optimize (2)
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1e5+5, MOD = 1e9+7;
vector<vector<int>> ad(MAXN); vector<long long> d[2];
int n, a, b;

void find(int s, int w) {
    d[0][s] = d[1][s] = 1;
    for (int x : ad[s]) {
        if (x != w) {
            find(x, s);
            d[0][s] = (d[0][s] * (d[0][x] + d[1][x])) % MOD;
            d[1][s] = (d[1][s] * d[0][x]) % MOD;
        }
    }
    d[0][s] %= MOD;
    d[1][s] %= MOD;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    d[0].resize(MAXN);
    d[1].resize(MAXN);

    for (int x = 1; x < n; x++) {
        cin >> a >> b;
        ad[a].push_back(b);
        ad[b].push_back(a);
    }

    find(1, 1);
    cout << (d[0][1] + d[1][1]) % MOD << '\n';
    return 0;
}