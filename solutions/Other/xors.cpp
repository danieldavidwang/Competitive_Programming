#include <bits/stdc++.h>
using namespace std;
int n, a; long long x, y;

int main() {
    cin >> n;
    while (n--) {
        cin >> a;
        x ^= a; y += a;
    }
    cout << y-x << '\n'; return 0;
}