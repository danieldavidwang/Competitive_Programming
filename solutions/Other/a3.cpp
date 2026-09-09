#include <bits/stdc++.h>

using namespace std;

short k;

short findNext() {
    short x = 192;
    while (x <= k) {
        x += 250;
    }
    return x;
}

int main() {
    short t; cin >> t;
    
    for (short i = 0; i < t; i++) {
        cin >> k;
        short l = findNext();
        cout << l << endl;
    }
}