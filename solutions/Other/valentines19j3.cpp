#include <bits/stdc++.h>
using namespace std;
string s;
unsigned long long dp[6];

int main() {
    cin >> s;
    dp[0] = 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'l') dp[1] += dp[0]; else if (s[i] == 'o') dp[2] += dp[1]; else if (s[i] == 'v') dp[3] += dp[2]; else if (s[i] == 'e') dp[4] += dp[3];
    }
    cout << dp[4] << '\n';
}