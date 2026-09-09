#include <bits/stdc++.h>
using namespace std;
int T, N;

int main() {
    cin >> T;
    while(T--) {
        cin >> N;
        if (N == 2) cout << N << '\n';
        else cout << N-1 << '\n';
    }
}