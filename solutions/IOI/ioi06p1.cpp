#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int a, b, ans = 0; string g, s;
unordered_map<char, int> currFreq, target;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b >> g >> s;
    for (char i = 'a'; i <= 'z'; i++) { currFreq[i] = 0; target[i] = 0; }
    for (char i = 'A'; i <= 'Z'; i++) { currFreq[i] = 0; target[i] = 0; }
    for (int i = 0; i < a; i++) { currFreq[s[i]]++; target[g[i]]++; }
    if (currFreq == target) ans++;
    for (int i = a; i < b; i++) {
        currFreq[s[i]]++;
        currFreq[s[i-a]]--;
        if (target == currFreq) ans++;
    }
    cout << ans << '\n'; return 0;
}