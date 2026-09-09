#include <bits/stdc++.h>
using namespace std;
int a, b, ans = 0;

int count(int x) {
    int cnt = 0;
    for (int i = 1; i <= x; i++) {
        if (x % i == 0) cnt++;
    }
    return cnt;
}

int main() {
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        int y = count(i);
        if (y == 4) ans++;
    }
    cout << "The number of RSA numbers between " << a << " and " << b << " is " << ans << '\n';
}