#include <bits/stdc++.h>
using namespace std;
int N, i, j;

int main() {
    cin >> N >> i >> j;
    if (abs((N - i*i)) < abs((N - j*j))) cout << "1\n";
    else cout << "2\n";
}