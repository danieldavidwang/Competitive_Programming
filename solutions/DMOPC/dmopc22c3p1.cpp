#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
long long N, M;
long long product;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    product = N*M;
    
    if (N % 2 == 1 && M % 2 == 1) {
        long long result = max(N*(M/2), M*(N/2));
        product -= result;
        cout << product << " " << result << '\n';
    } else { cout << product/2 << " " << product/2 << '\n'; return 0; }
    return 0;
}