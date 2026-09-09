#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int n, m;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        if (i != 0) cout << '\n';
        for (int j = 0; j < m; j++) cout << (((i^(i>>1)) << 10) | (j^(j>>1))) << " ";
    }
    cout << '\n'; return 0;
}