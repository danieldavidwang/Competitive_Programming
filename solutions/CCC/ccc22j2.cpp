#include <bits/stdc++.h>
using namespace std;
int N, x, y, val, cnt=0;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        val = 5*x-3*y;
        if (val > 40) cnt++;
    }
    if (N == cnt) { cout << cnt; cout << "+\n"; }
    else cout << cnt << '\n';
}