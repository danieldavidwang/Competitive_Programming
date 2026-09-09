#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+6;
int n, ans, nums[MM]; unordered_set<int> us;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    for (int i = 0; i < 10; i++) {
        ans = 0;
        cin >> n; memset(nums, 0, sizeof(nums)); us.clear();
        for (int j = 0, x; j < n; j++) { cin >> x; nums[i] = x; us.insert(x); }
        for (int k = 1; k < MM; k++) {
            if (us.find(k) != us.end()) {
                for (int l = k+k; l < MM; l += k) if (us.find(l) != us.end()) ans += 1;
            }
        }
        cout << ans << '\n';
    }
}