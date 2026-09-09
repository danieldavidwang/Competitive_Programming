#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int N;
string s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    while(N--) {
        cin >> s;
        int cnt = 1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == s[i+1]) cnt++;
            else {
                cout << cnt << " " << s[i] << " ";
                cnt = 1;
            }
        }
        cout << '\n';
    }
}