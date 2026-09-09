#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
    cin >> n;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        if (x==1) cout << y-1 << '\n';
        else if (y==1) cout << x-1 << '\n';
        else cout << x*y-1 << '\n';
    }
}