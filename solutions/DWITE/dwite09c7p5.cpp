#pragma GCC optimize (2)
#include "bits/stdc++.h"
using namespace std;
int N, K, t = 5;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (t--) {
        cin >> N >> K;
        if (K & (1 << (N - 1))) cout << "ON\n";
        else cout << "OFF\n";
    }
    return 0;
}