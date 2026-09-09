#include <bits/stdc++.h>
using namespace std;
int N, K, D, ans;

int main() {
    cin >> N >> K >> D;
    ans = N;
    for (int i = 0; i < D; i++) {
        ans *= K;
    }
    cout << ans << '\n';
}