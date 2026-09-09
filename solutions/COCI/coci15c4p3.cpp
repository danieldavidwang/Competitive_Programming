#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int temp = 0;
        for (int j = 1, x; j <= n; j++) { cin >> x; temp |= x; }
        cout << temp << " ";
    }
    cout << '\n'; return 0;
}