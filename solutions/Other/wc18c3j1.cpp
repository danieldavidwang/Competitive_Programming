#include <bits/stdc++.h>
using namespace std;
int P, B, D;

int main() {
    cin >> P >> B >> D;
    cout << P/B*D + (P%B) << '\n';
}