#include <bits/stdc++.h>
using namespace std;
int a, b, c, ans = 91;

int main() {
    cin >> a >> b >> c;
    ans += a;
    ans += (3*b);
    ans += c;
    cout << "The 1-3-sum is " << ans << '\n';
}