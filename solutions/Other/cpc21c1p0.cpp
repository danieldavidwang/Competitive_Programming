#include <bits/stdc++.h>
using namespace std;
set<char> letters;
string s;

int main() {
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        letters.insert(c);
    }
    for (int i = 97; i <= 122; i++) {
        if (find(letters.begin(), letters.end(), char(i)) != letters.end()) continue;
        else { cout << char(i); return 0; }
    }
}