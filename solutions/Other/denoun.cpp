#include <bits/stdc++.h>
using namespace std;
int n, cnt;
string s;

int main() {
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        cnt = 0;
        getline(cin, s);
        for (int j = 0; j < s.length(); j++) {
            if (s[j] >= 'A' && s[j] <= 'Z') cnt++;
        }
        cout << cnt << '\n';
    }
}