#include <bits/stdc++.h>
using namespace std;
int n, dp[1003];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i = 1, val; i <= n; i++) {
		cin >> val;
		for (int j = i; j <= n; j++) dp[j] = max(dp[j], val + dp[j-i]);
	}
	cout << dp[n] << '\n';
    return 0;
}