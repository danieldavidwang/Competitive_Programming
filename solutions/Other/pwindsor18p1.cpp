#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
    cin >> s;
    size_t found = s.find("java", 0, 4);
    if (found != string::npos) { cout << found << '\n'; }
    else { cout << s.length() << '\n'; } 
}