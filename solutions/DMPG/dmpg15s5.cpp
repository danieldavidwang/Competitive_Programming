#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+4;
bool a[MM][MM], b[MM][MM];
int N, M, h, w, x, y, ans = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    memset(a, 0, sizeof(a));
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        cin >> x >> y >> w >> h;
        a[++x][++y] ^= 1;
        a[x][y+h] ^= 1;
        a[x+w][y] ^= 1;
        a[x+w][y+h] ^= 1;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            b[i][j] ^= a[i][j];
            b[i][j] ^= b[i-1][j];
            b[i][j] ^= b[i][j-1];
            b[i][j] ^= b[i-1][j-1];
            if (b[i][j] == true) ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}