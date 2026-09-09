#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int N, maxx = 0, x, y;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    while(N--) {
        cin >> x >> y;
        if (y-x > maxx) maxx = y-x;
    }
    cout << maxx << '\n';
}