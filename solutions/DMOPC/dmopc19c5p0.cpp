#include <bits/stdc++.h>
using namespace std;
int N, C, x;
string s;

int main() {
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> s >> x;
        if (C < x) cout << s << " will advance\n";
        else cout << s << " will not advance\n";
    }
    return 0;
}