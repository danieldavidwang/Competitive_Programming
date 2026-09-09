#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    if (n == 2) { cout << "-1\n"; return 0; }
    if (n == 1) { cout << "1\n"; return 0; }
    if (n == 3) { cout << "1 3 2\n"; return 0; }
    cout << "1 3 2 ";
    for (int i = 4; i <= n; i++) {
        if (i == n) cout << i << '\n';
        else cout << i << " ";
    }
    return 0;
}