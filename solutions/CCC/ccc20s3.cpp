#pragma GCC optimize (2)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5+9, base1 = 137, base2 = 10007, modular = 1e9+7;
typedef long long ll;

ll hsh[MAX], pw[MAX], hsh2[MAX], pw2[MAX];
string s, t; unordered_set<ll> us;

ll getSubHash (int x, int y) {
    ll v1 = (hsh[y]-hsh[x-1]*pw[y-x+1]%modular + modular) % modular;
    ll v2 = (hsh2[y]-hsh2[x-1]*pw2[y-x+1]%modular + modular) % modular;
    return (v1 << 31) | (v2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> s >> t; vector<int> ve1(26), ve2(26);
    int n = s.size(); int m = t.size();
    
    for (char c: s) ve1[c-'a']++;
    pw[0] = 1; pw2[0] = 1;
    
    for (int i = 1; i <= m; i++) {
        pw[i] = pw[i-1]*base1 % modular;
        hsh[i] = (hsh[i-1]*base1+t[i-1]) % modular;
        pw2[i] = pw2[i-1]*base2 % modular;
        hsh2[i] = (hsh2[i-1]*base2+t[i-1]) % modular;
    }

    for (int j = 1; j <= m; j++) {
        ve2[t[j-1]-'a']++;
        if (j > n) ve2[t[j-n-1] - 'a']--;
        if (ve1 == ve2) us.insert(getSubHash(j-n+1, j));
    }
    cout << us.size() << '\n';
}