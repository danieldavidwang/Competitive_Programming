#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int N, cnt = 0; string s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'I' && s[i+1] == 'U') cnt++;
    }
    cout << N-cnt << '\n';
}