#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, p = 0; vector<ll> prime;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    vector<bool> pp(1e5+1, 1), ppp(1e8+1, 1);
    for (int x = 2, y; x < pp.size(); x++) if (pp[x]) for (y = x*x, prime.push_back(x); y < pp.size(); pp[y] = false, y += x);
    for (auto &x : prime) for (ll y = n+x-((n%x) ? n%x : x); y <= m-m%x; y+=x) ppp[y-n] = false;
    for (ll x = n; x < m; p += ((x < 1e5+1 && pp[x]) || ppp[x-n]), x++);
    cout << p << '\n';
}