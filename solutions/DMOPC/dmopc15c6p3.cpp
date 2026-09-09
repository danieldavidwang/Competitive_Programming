#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
long long n, m, k, s = 0; int a, b, w = numeric_limits<int>::max();

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n >> k;
    
    if (k == 0) {
        cout << "0";
        return 0;
    }
    
    vector<int> pp(m + 2, n), dd(m + 2);
    
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        dd[a]--;
        dd[b + 1]++;
    }
    
    for (int i = 1, aa = 0; i < m + 2; ++i) {
        aa += dd[i];
        pp[i] += aa;
    }
    
    a = 1, b = 1;
    
    while (s < k && b <= m) s += pp[b++];
    
    if (s < k) {
        cout << "-1";
        return 0;
    }
    
    --b;
    
    while (b <= m) {
        while (s >= k) s -= pp[a++];
        --a;
        s += pp[a];
        w = min(w, b - a + 1);
        s += pp[++b];
    }

    cout << (w == numeric_limits<int>::max() ? -1 : w);
    return 0;
}