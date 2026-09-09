#include <bits/stdc++.h>
using namespace std;
int n, ans = 1;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    vector<int>a(n),t(n), pa(n+1);
    for (auto &x : a) cin >> x;
    for (auto &x : t) cin >> x;
    for (int i = 0; i < n; i++) pa[a[i]]=i;
    for (int i = 1; i < n; i++) if (pa[t[i]] != pa[t[i-1]] + 1) ans++;
    cout << ans << '\n';
    return 0;
}