#include <bits/stdc++.h>
using namespace std;
const int MM = 5e1+9, SUBS = (1<<25);
int m, n, k, s1, s2, tot, in[MM], sub1[SUBS], sub2[SUBS]; long long ans;

int solve(int arr[SUBS], int lft, int rgt) {
	int sz = rgt - lft, ms = (1<<sz);
	for (int i = 0; i < ms; i++) {
		tot = 0;
		for (int j = sz-1; j >= 0; j--) if (i & (1<<j)) tot += in[lft+j];
		arr[i] = tot;
	}
	return ms;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k; m = n / 2;
	for (int i = 0; i < n; i++) cin >> in[i];
	int s1 = solve(sub1, 0, m), s2 = solve(sub2, m, n), ptr = s2 - 1;
	sort(sub1, sub1 + s1);
	sort(sub2, sub2 + s2);
	for (int i = 0; i < s1; i++) { while ((sub1[i]+sub2[ptr]) > k && ptr >= 0) ptr--; ans += ptr+1; }
    cout << ans << '\n'; return 0;
}