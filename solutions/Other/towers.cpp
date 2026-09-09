#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const long long MM = 1e6+1;
long long n, arr[MM], ans = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    for (long long i = 1; i < n-1; i++) {
        if ((arr[i-1] < arr[i]) && (arr[i] < arr[i+1])) ans++;
    }
    cout << ans << '\n';
}