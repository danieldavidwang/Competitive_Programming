#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
 
int LIS(vector<int> &v) {
    if (v.size() == 0) return 0;
 
    vector<int> last(v.size(), 0);
    int len = 1;
    last[0] = v[0];
 
    for (int i = 1; i < v.size(); i++) {
        auto b = last.begin(), e = last.begin() + len;
        auto it = lower_bound(b, e, v[i]);
        if (it == last.begin() + len) last[len++] = v[i];
        else *it = v[i];
    }
    return len;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x; v.push_back(x);
    }
    cout << LIS(v);
    return 0;
}