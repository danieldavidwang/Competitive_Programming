#pragma GCC optimize (2)
#include <bits/stdc++.h>
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;
const int MM = 2e2+2;
int n, dp[MM][MM];
vector<int> v(MM);

int solve(int l, int r) {
    if (l == r) return v[l];
    if (l+1 == r) return 0;
    int &curr = dp[l][r];
    if (~curr) return curr;
    for (int i = l+1; i < r; i++) curr = max(solve(l, i) + (v[i]+v[l]+v[r]) + solve(i, r), curr);
    return curr;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (1) {
        cin >> n; 
        if (n == 0) return 0;
        mem(dp, -1);
        for (int i = 0; i < n; i++) cin >> v[i];
        cout << solve(0, n-1) << '\n';
    }
    return 0;
}