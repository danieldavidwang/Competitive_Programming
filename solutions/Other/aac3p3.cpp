#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+6;
int lft, rgt, p, n, a[MM], b[MM]; string s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n); rgt = n-1;
    s.resize(n, 'E');
    while (lft < rgt) { s[p] = 'B'; b[p++] = a[lft]; s[p] = 'S'; b[p++] = a[rgt]; lft += 1; rgt -= 1; }
    if (rgt == lft) b[p++] = a[lft];
    for (int i = 0; i < n; i++) { cout << b[i]; if (i != n-1) cout << " "; }
    cout << '\n' << s << '\n'; return 0;
}