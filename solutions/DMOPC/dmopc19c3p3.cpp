#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1.5e5+5;
int n, x; long long ans, temp; vector<int> v(2*MM);

void func(int m) {
    m += MM;
    for (; m < v.size(); m += (m & -m)) v[m]++;
}

int solve(int m) {
    int ret = 0; m += MM;
    for (; m > 0; m -= (m & -m)) ret += v[m];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    func(0);
    while (n--) {
        cin >> x;
        if (x != 2) temp++; else temp--;
        ans += solve(temp-1); 
        func(temp);
    }
    cout << ans << '\n'; return 0;
}