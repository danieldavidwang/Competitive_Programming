#include <bits/stdc++.h>
using namespace std;
int a, b, n;
vector<int> m = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};

int main() {
    cin >> a >> b >> n;
    for (int i = 0, y; i < n; i++) { cin >> y; m.push_back(y); }
    sort(m.begin(), m.end());
    vector<long long> dp(m.size());
    dp[0] = 1;
    for (int i = 1; i < dp.size(); i++) {
        for (int j = i-1; j >= 0; j--) {
            if ((a <= m[i] - m[j]) && (m[i] - m[j] <= b)) dp[i] += dp[j];
        }
    }
    cout << dp.back() << '\n';
}