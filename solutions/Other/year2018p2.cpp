#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
bool sieved[MM];
int N, ans = 0;

void sieve() { 
    sieved[1] = true;
    for (int p = 2; p < MM; p++) {
        if (!sieved[p]) { for (int i = 2*p; i < MM; i += p) sieved[i] = true; }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    sieve();
    for (int i = 1, x; i <= N; i++) {
        cin >> x;
        if (!sieved[x]) ans++;
    }
    cout << ans << '\n';
}