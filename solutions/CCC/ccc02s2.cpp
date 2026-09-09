#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    int a, b;
    cin >> a >> b;
    if (a % b == 0) cout << a / b << '\n';
    else {
        int commonDivisor = gcd(a, b);
        a /= commonDivisor;
        b /= commonDivisor;
        if (a > b) cout << a / b << ' ' << a % b << '/' << b << '\n';
        else cout << a << '/' << b << '\n';
    }
    return 0;
}