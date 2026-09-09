#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 3e2+2;
int N, K, dp[MM][MM];

int fun(int i, int j) {
	if (j != 0 && i == 0) return 1;
	if (i < 0 || (i != 0 && j == 0)) return 0;
	if (dp[i][j]) return dp[i][j];
	return dp[i][j] = fun(i, j-1) + fun(i-j, j);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> K;
	cout << fun(N - K, K) << '\n';
}