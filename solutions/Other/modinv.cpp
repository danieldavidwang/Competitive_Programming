#include <bits/stdc++.h>
unsigned long long a, b, mod, ans, xx = 1, xy;
using namespace std;

int main() { 
    cin >> a >> b;
    mod = b;

    while (a > 0 && b > 0) {
        if (a > b) {
            xx += xy * (a/b);
            a %= b;
        }
        else {
            xy += xx * (b/a);
            b %= a;
        }
    }
    ans = a ? xx : mod-xy;
    cout << ans << '\n';
}