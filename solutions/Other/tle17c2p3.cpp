#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef double db;
int n, r, a, b, c, d, e;

db dis(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

db velocity(int a, int b, int v, db dist) {
    return (v*(b-a)) / dist;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> r >> a >> b >> c >> d >> e;
    r = pow(r, 2);
    db wx = a, wy = b, wxx = velocity(a, c, e, dis(a, b, c, d)), wyy = velocity(b, d, e, dis(a, b, c, d));
    for (int i = 2; i <= n; i++) {
        cin >> a >> b >> c >> d >> e;
        db xP = wx - a, xV = wxx - velocity(a, c, e, dis(a, b, c, d)), yP = wy - b, yV = wyy - velocity(b, d, e, dis(a, b, c, d));
        db A = xV*xV + yV*yV, B = 2*(xP*xV + yP*yV), C = xP*xP + yP*yP, T = 0.0;
        if (A) T = max(-B / (2*A), 0.0);
        db dist = A*pow(T, 2) + B*T + C;
        if (dist <= r) cout << i << '\n';
    }
    return 0;
}