#include <bits/stdc++.h>
using namespace std;
int T;
string s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int j = 0; j < T; j++) {
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        cout << s << '\n';
    }
    cout << '\n';
}