#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int n, t;
vector<int> lis;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--) {
        lis.clear();
        cin >> n;
        for (int i = 1, x; i <= n; i++) {
            cin >> x;
            if (lis.empty() || x > lis.back()) lis.push_back(x);
            else *lower_bound(lis.begin(), lis.end(), x) = x;
        }
        cout << lis.size() << '\n';
    }
    return 0;
}