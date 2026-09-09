#include <bits/stdc++.h>
using namespace std;
int N;
string s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    if (N % 2 == 1) { cin >> s; cout << s << '\n'; return 0; }
    else {
        cin >> s;
        s == "left" ? cout << "right\n" : cout << "left\n";
    }
}