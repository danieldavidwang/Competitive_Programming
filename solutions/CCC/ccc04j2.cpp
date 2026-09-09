#include <bits/stdc++.h>
using namespace std;
int x, y;

int main() {
    cin >> x >> y;
    while(x <= y) {
        cout << "All positions change in year " << x << '\n';
        x += 60;
    }
}