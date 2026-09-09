#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 5e3+3;
int N, a[MM], dp[MM][MM];
ll differL[MM][MM];

ll getL(int l) {
    priority_queue< ll,vector<ll>,greater<ll> > q;
    q.empty();
    if (l == 1) return 0;
    for (int i = 1; i <= N-l+1; i++) { q.push(differL[l][i]); }
    return q.top();
}

void solve() {
    for (int i = 1; i <= N; i++)
        for (int j = i+1; j <= N; j++)
            dp[i][j] = abs(a[i]-a[j]);
    
    for (int i = 2;i <= N; i++)
        for (int j=1; j <=N-i+1; j++)
            differL[i][j] = differL[i-2][j+1] + dp[j][j+i-1];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i];
    solve();
    for (int i = 1; i <= N; i++) { cout << getL(i) << " "; }
    cout << '\n';
    return 0;
}