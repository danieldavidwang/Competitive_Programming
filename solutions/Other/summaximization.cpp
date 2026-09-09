#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int q; string s1, s2; long long ans, tot; bool ch = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> q;
    while (q--) {
        ans = 0, tot = 0;
        cin >> s2 >> s1;
        for (auto &i: s1) i -= '0';
        while (s1.size() > s2.size()) s2 = "0" + s2;
        for (auto &i: s2) i -= '0';
        bool ch = 0;
        for (int i = 0; i < s1.size(); i++) {
            ch |= (s1[i] > s2[i]);
            if (ch) {
                long long cur = tot + s1[i]-1 + 9*(s1.size()-i-1);
                ans = max(ans, cur);
            }
            tot += s1[i];
        }
        if (ans >= tot) cout << ans << '\n';
        else cout << tot << '\n';
    }
    return 0;
}