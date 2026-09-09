#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e4+7;
int n; ll t;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    vector<ll> v(n), vv(n);
    while (n--) { cin >> v[n]; vv[n] = v[n]; }
    sort(v.begin(), v.end()); sort(vv.rbegin(), vv.rend());
    for (int i = 0; i < v.size(); i++) t += (v[i]*vv[i]), t %= MOD;
    cout << t << '\n';
    return 0;
}