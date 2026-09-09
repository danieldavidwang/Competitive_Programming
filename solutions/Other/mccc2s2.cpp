#pragma GCC optimize (2)
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int n; string s; deque<char> ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    for (auto &i: s) {
        if (ans.front() >= i) ans.push_front(i);
        else if (ans.empty()) ans.pb(i);
        else ans.pb(i);
    }
    for (auto &i: ans) cout << i;
    cout << '\n'; return 0;
}