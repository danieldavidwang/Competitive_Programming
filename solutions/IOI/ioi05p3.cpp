#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int n, a1, a2, lft = INT_MAX, rgt = INT_MIN;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> a2;
        a2 -= (a1-a2);
        if (!(i%2)) rgt = max(rgt, (a1 - a2) / 2);
        else lft = min(lft, (a2 - a1) / 2);
        a1 = a2;
    }
    if (rgt <= lft) cout << lft-rgt+1 << '\n';
    else cout << 0 << '\n';
}