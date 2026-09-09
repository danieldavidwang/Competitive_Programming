#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3+3;
int d, N, v[MM];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    while (cin >> N) {
        for (int i = 0; i < N; i++) cin >> v[i];
        d = v[N-1] - v[N-2];
        int j = N-1;
        for (; j > 0; j--) if (v[j] - v[j-1] != d) break;
        cout << j+1 << '\n';
    }
}