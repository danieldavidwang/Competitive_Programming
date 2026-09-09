#include <bits/stdc++.h>
using namespace std;
int n, sum = 0;

int main() {
    cin >> n;
    for (int i = 0, x; i < n ; i++) {
        cin >> x;
        sum += abs(x);
    }
    cout << sum << '\n';
}