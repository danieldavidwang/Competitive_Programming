#pragma GCC optimize (2)
#include <iostream>
#include <cmath>
using namespace std;
long long sx, sy, sz, tx, ty, tz;
int d; char t;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> sx >> sy >> sz >> tx >> ty >> tz;
    tx -= sx; ty -= sy; tz -= sz;
    long long ans = tx * tx + ty * ty + tz * tz;
    while (1) {
        cin >> d >> t;
        if ((tx - d < 0 && tx > 0) || (tx - d > 0 && tx < 0)) ans = min(ans, ty * ty + tz * tz);
        tx -= d;
        ans = min(ans, tx * tx + ty * ty + tz * tz);
        if (t == 'E') { printf("%.2lf\n", sqrt(ans)); return 0; }
        if (t == 'R') {
            swap(tx, ty);
            tx = -tx;
        } else if (t == 'L') {
            swap(tx, ty);
            ty = -ty;
        } else if (t == 'U') {
            swap(tx, tz);
            tz = -tz;
        } else if (t == 'D') {
            swap(tx, tz);
            tx = -tx;
        }
    }
}