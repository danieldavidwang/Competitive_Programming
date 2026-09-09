#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int n, nn; vector<int> v, r;

bool check(int x) {
    v.clear(); r.clear();
    nn = n;
    while(nn) { r.push_back(nn % x); v.push_back(nn % x); nn /= x; }
    reverse(r.begin(), r.end());
    return v == r;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 2; i*i <= n; i++) if (check(i)) cout << i << '\n';
    for (int i = sqrt(n); i > 0; i--) if (!(n%i)) if (i < (n/i)-1) cout << (n/i)-1 << '\n';
    return 0;
}