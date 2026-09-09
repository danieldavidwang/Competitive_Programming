#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int diff = 0;

int main() {
    cin >> s1 >> s2;
    int N = s1.length();
    for (int i = 0; i < N; i++) {
        if (s1[i] != s2[i]) diff++;
    }
    diff == 1? cout << "LARRY IS SAVED!\n" : cout << "LARRY IS DEAD!\n";
}