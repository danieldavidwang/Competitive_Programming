#include <bits/stdc++.h>
using namespace std;
const int MM = 3e7+7;
int a, b, c, d, Q, x, dp[MM];

int fun(int x) {
    if (x <= 0) return 1;
    if (x >= MM) return fun(x/a-b) + fun(x/c-d);
    if (dp[x]) return dp[x];
    return dp[x] = fun(x/a-b) + fun(x/c-d);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b >> c >> d >> Q;
    for (int i = 1; i < MM; i++) fun(i);
    while (Q--) { cin >> x; cout << fun(x) << '\n'; }
    return 0;
}