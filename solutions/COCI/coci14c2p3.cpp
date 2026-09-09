#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MAXN = 5001;
int a[MAXN], dp[MAXN], n, k, minMinutes = 0;
pi sk[MAXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k;
    for(int i = 0, x; i < n; i++) {
        cin >> x;
        sk[i] = make_pair(x, i);
    }
    sort(sk, sk + n);

    for(int i = 0; i < n; i++)
        a[sk[i].second] = i / k;

    for(int i = 0; i < n; i++) {
        dp[i] = 1;
        for(int j = i-1; j >= 0; j--)
            if(a[i] >= a[j]) dp[i] = max(dp[i], 1+dp[j]);
        minMinutes = max(minMinutes, dp[i]);
    }
    cout << n-minMinutes << '\n';
}