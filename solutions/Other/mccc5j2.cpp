#include <bits/stdc++.h>
using namespace std;
int x, y;

int main() {
    cin >> x >> y;
    if (x >= 20 && x <= 23 && y >= 6 && y <= 9) {
        if ((24-x) + y >= 8 && (24-x) + y <= 10) cout << "Healthy\n";
        else cout << "Unhealthy\n";
    } else {
        cout << "Unhealthy\n";
    }
}