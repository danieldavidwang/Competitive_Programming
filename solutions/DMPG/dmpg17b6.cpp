#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
long x, n; double c;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    while (n--) {
        cin >> x;
        c += log2(x);
    }
    cout << (int) c+1 << '\n';
}