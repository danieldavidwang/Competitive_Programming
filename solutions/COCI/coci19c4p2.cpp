#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+6;
int n, k, g, h[MM], cnt[MM];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        cnt[h[i]]++;
        if (h[i] > k) g++;
    }
    for (int i = 0; i < n; i++) {
        int ans = 0;
        if (h[i] < k) { cout << "0 "; continue; }
        else if (h[i] == k) { cout << g << " "; continue; }
        for (int j = 1; j*j <= h[i]-k; j++) {
            if ((h[i]-k)%j) continue;
            if (h[i]%j == k) ans += cnt[j];
            if (j*j != h[i]-k && h[i] % ((h[i]-k)/j) == k) ans += cnt[(h[i]-k)/j];
        }
        if (!k) ans--;
        cout << ans << " ";
    }
    cout << '\n';
    return 0;
}