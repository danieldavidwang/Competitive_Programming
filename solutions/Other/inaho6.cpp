#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;

int main() {
    cin >> n;
    if (n > 140) { cout << "0.438283\n0.360592\n"; return 0; }
    else if (n == 0) { cout << "1\n0\n"; return 0; }
    else {
        complex<long double> b(0, 1), e(0, 1);
        for (int i = 1; i < n; i++) e = pow(b, e);
        cout << e.real() << '\n' << e.imag() << '\n';
    }
    return 0;
}