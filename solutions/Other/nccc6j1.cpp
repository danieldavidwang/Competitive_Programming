#include <bits/stdc++.h>
using namespace std;
int a, b;

int main() {
    cin >> a >> b;
    if (a == b) return 0;
    a > b ? cout << "CS452\n": cout << "PHIL145\n";
}