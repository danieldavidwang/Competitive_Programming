#include <bits/stdc++.h>
using namespace std;
int N, ans;

int main() {
    cin >> N;
    while (N>1) {
        for (int i = 2; i <= N; i++) {
            if (!(N%i)) {
                int x = N/i;
                N -= x;
                ans += N/x;
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}