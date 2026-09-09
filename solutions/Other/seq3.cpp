#include <bits/stdc++.h>
using namespace std;
int N, K;

int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        if (i < N) cout << "0 ";
        else cout << (K) << '\n';
    }
}