#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
long long psa[MM];
int n; long long ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> psa[i];
        psa[i] += psa[i-1];
    }
    for (int i = 1; i <= n; i++) {
        ans += (psa[n-i+1]-psa[i-1]);
        cout << ans << '\n';
    }
}