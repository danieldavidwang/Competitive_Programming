#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5+5;
int N, ans = 1e9;
long long M, ssum = 0, a[MM];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> a[i];
    int l = 0, r = 0;
    ssum = a[0];
    
    while (r < N) {
        if (ssum >= M) { ans = min(r-l+1, ans); ssum -= a[l++]; }
        else ssum += a[++r];
    }
    if (ans == 1e9) cout << "-1\n";
    else cout << ans << '\n';
    return 0;
}