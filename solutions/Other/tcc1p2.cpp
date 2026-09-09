#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int n, k;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n >> k; vector<int> a(n+1), x(k+1); vector<int> l(k+1, n+1);
    vector<long long> psa(n+1), rmv(k+1);
    
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        psa[i] = psa[i-1] + a[i];
    }
    
    for (int i=1; i<=k; i++) cin >> x[i];
    
    for (int i=n; i>0; i--) {
        int v = a[i];
        if (v <= k) {
            int s, e;
            if (l[v] <= i) {
                e = max(0, l[v]-1);
                s = max(0, l[v]-x[v]-2);
            } else {
                e = i;
                s = max(0, i-x[v]-1);
            }
            rmv[v] += psa[e] - psa[s];
            l[v] = s+1;
        }
    }
    
    for (int i=1; i<=k; i++) cout << psa[n] - rmv[i] << "\n";
    return 0;
}