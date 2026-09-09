#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+6;
int n, x, ans, in[MM];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> x; if (x) in[x]++; }
	for (int i = 1; i <= n; i++) if (in[i] == 0) ans++;
	cout << ans << '\n';
}