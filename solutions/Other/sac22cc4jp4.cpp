#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, rem, a[MM], ans[MM];
bool vis[MM];
long long K;

int main() {
    cin >> N >> K;
    K--;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) {
        if (vis[i]) continue;
        vector<int> v;
        for (int cur = i; !vis[cur]; cur = a[cur]) { v.push_back(cur); vis[cur] = true; }
        rem = K%v.size();
        for (int j=0; j<v.size(); j++) ans[v[(j + rem)%v.size()]] = v[j];
    }
    for (int i = 1; i <= N; i++) cout << ans[i] << " ";
    cout << '\n'; return 0;
}