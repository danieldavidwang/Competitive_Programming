#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int n, k; vector<int> v(MM), vv(MM);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> v[i], vv[v[i]] = i;
    for (int i = n; i > 0 && k; i--) if ((vv[i]) ^ (n+1-i)) swap(v[vv[i]], v[n-i+1]), swap(vv[v[vv[i]]], vv[v[n+1-i]]), k--;
    for (int i = 1; i <= n; i++) cout << v[i] << " ";
    cout << '\n'; return 0;
}