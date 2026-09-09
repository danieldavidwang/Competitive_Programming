#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, sb, bb, ans = INT_MAX;
vector<pair<int, int>> v(11);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) { cin >> sb >> bb; v[i] = {sb, bb}; }
    int maxsub = 1 << n;
    for (int i = 1; i < maxsub; ++i) {
        int prod = 1, sum = 0;
        for (int j = n; j >= 0; j -= 1) {
            if (i & (1 << j)) {
                prod *= v[j].first;
                sum += v[j].second;
            }
        }
        ans = min(ans, abs(prod - sum));
    }
    cout << ans << '\n'; return 0;
}