#include <bits/stdc++.h>
using namespace std;
int N, ans = 0;
string s;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;
        if (s.length()<=10) ans++;
    }
    cout << ans << '\n';
}