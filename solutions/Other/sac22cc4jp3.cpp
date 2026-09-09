#include <bits/stdc++.h>
using namespace std;
int n, t, sol;
double x, y, best = 3e9, pi = 3.14159265358979;

int main() {
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        double angle = 360 + atan2(y, x)*180 / pi;
        if (angle >= 360) angle -= 360;
        double dif = min(abs(angle-t), 360 - abs(angle-t));
        if (dif < best) { sol = i; best = dif; }
    }
    printf("%d\n", sol);
}