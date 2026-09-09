#include <bits/stdc++.h>
using namespace std;
int X, M, ans = 0;

int main() {
    cin >> X >> M;
    for (int i = 1; i < M; i++) {
        int product = X*i;
        if (product % M == 1) {
            ans = i;
            break;
        }
    }
    ans? cout << ans << '\n': cout << "No such integer exists.";
}