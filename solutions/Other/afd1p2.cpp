#include <bits/stdc++.h>
using namespace std;
string s1, s2 = "";

int main() {
    cin >> s1;
    s2 += (s1[3]);
    s2 += (s1[2]);
    s2 += (s1[7]);
    s2 += (s1[0]);
    s2 += (s1[5]);
    s2 += (s1[1]);
    s2 += (s1[4]);
    s2 += (s1[6]);
    cout << s2 << '\n';
}