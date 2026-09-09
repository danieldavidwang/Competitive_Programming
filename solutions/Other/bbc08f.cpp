#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int n, ls, le, x, goat; long ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> x; goat = x;
    for (int i = 0; i < n; i++) {
        cin >> ls >> le;
        if (ls < x) {
            if (le > x) goat = min(le, goat);
            else {
                ans += x-le;
                goat = x;
                x = le;
            }
        }
        else if (le > goat) {
            if (ls < goat) x = max(ls, x);
            else {
                ans += ls-goat;
                x = goat;
                goat = ls;
            }
        }
        else if (le < goat && ls > x) x = ls, goat = le;
    }
    cout << ans << '\n';
    return 0;
}