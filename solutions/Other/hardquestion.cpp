#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
double g, c, t, t1, t2, vf, x;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> g >> c >> t;
    t1 = (sqrt(c*c+2*g*c*t))/g - (c/g);
    t2 = t - t1;
    vf = g*t1;
    x = (g*t1*t1/4) + (c*t2/2);
    cout << x << '\n' << vf << '\n';
    return 0;
}