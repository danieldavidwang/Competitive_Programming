#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int n, m, avg;

bool checkP(int n) {
    if (n < 10) return true;
    int rev = 0, temp = n;
    while (temp != 0) {
        rev = (rev * 10) + (temp % 10);
        temp = temp / 10;
    }
    return (rev == n);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    avg = (n+m) / 2;

    for (int i = 1; i < avg; i++) {
        if (checkP(avg+i)) { cout << avg+i << '\n'; return 0; }
        if (checkP(avg-i)) { cout << avg-i << '\n'; return 0; }
    }
    return 0;
}