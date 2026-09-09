#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
int n, v, b1, b2, can, point, arr[MM], dp[MM], ans[MM];

struct s {
	int a, b, c;
	bool operator<(const s &i) { return i.c > c; }
};

s q[MM];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> v;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 0; i < v; i++) { cin >> b1 >> b2; q[i] = {i, b1, b2}; }
	sort(q, q+v);
	memset(dp, 63, sizeof(dp)); dp[0] = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int j = arr[i]; j <= 1e4; j++) dp[j] = min(dp[j-arr[i]]+1, dp[j]);

		while (q[point].c == i && v > point) {
			can = dp[q[point].b];
			if (can == 0x3f3f3f3f) ans[q[point].a] = -1;
			else ans[q[point].a] = can;
			point++;
		}
	}
	for (int i = 0; i < v; i++) cout << ans[i] << '\n';
	return 0;
}