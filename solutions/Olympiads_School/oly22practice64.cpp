#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>

using namespace std;

int counter = 0;

int main() {
    string x; cin >> x;
    
    for (int i = 0; i < x.length(); i++) {
        int y = int(x[i]);
        if ((y >= 65) && (y <= 90) && ((i+counter) % 5 != 0)) {
            while (((i+counter)%5) != 0) counter++;
        }
    }
    cout << counter;
}