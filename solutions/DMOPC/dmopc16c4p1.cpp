#include <bits/stdc++.h>
using namespace std;
int n; long long a;

int main() {
    cin >> n;
    while (n--) {
        cin >> a;
        a & (a-1) ? cout << 'F' : cout << 'T'; cout << '\n';
    }
    return 0;
}