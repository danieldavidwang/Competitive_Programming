#include <bits/stdc++.h>
using namespace std;
float avg = 0, AIF, req;

int main() {
    for (int i = 0, x; i < 6; i++) {
        cin >> x; avg += x;
    }
    cin >> AIF;
    avg /= 6;
    avg += AIF;
    cin >> req;
    if (avg >= req) cout << "yes\n";
    else cout << "no\n"; 
}