#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
string s;
vector<char> v;

int main() {
    cin >> s;
    for (char c: s) {
        if (v.empty()) v.push_back(c);
        else if (c > v.back()) v.push_back(c);
        else *lower_bound(v.begin(), v.end(), c) = c;
    }
    cout << 26-v.size() << '\n';
    return 0;
}