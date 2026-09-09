#include <bits/stdc++.h>
using namespace std;
const int mod = 42;
set<int> s;
int A;

int main() {
    for (int i = 0; i < 10; i++) {
        cin >> A;
        A %= 42;
        s.insert(A);
    }
    cout << s.size() << '\n';
}