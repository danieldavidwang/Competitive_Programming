#include <bits/stdc++.h>
using namespace std;
int s, x;

int main() {
    cin >> s >> x;
    s = (s+2)*3+16;
    x < s? cout << "No, it's too small :(\n" : cout << "Yes it fits!\n";
}