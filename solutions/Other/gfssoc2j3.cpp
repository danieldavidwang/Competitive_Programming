#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int cur, val;
char op;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> cur;
    while (1) {
        cin >> op;
        if (op == '=') break;
        cin >> val;
        if (op == 'P') cur += val;
        else if (op == 'M') cur -= val;
    }
    cout << cur << '\n';
}