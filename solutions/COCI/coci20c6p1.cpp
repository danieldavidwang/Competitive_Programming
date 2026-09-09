#include <bits/stdc++.h>
using namespace std;
const int MM = 1e2+2;
int n, m; char a[MM][MM], b[MM][MM];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(b, '.', sizeof(b)); cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            if (a[i][j] == '#') b[i][j] = b[i][j+1] = b[i+1][j] = b[i+1][j+1] = '#';
        }
    }
    for (int i = 1; i <= n; i++, cout << '\n') for (int j = 1; j <= m; j++) cout << b[i][j];
    return 0;
}