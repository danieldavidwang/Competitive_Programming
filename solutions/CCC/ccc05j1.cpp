#include <bits/stdc++.h>
using namespace std;
int x, y, z;
float total1 = 0, total2 = 0;

int main() {
    cin >> x >> y >> z;
    if (x > 100) total1 += (0.25*(x-100));
    if (x > 250) total2 += (0.45*(x-250));
    total1 += (0.15*y);
    total2 += (0.35*y);
    total1 += (0.2*z);
    total2 += (0.25*z);
    printf("Plan A costs %.2f\n", total1);
    printf("Plan B costs %.2f\n", total2);
    if (total1 > total2) {
        cout << "Plan B is cheapest.\n";
    } else if (total1 < total2) {
        cout << "Plan A is cheapest.\n";
    } else {
        cout << "Plan A and B are the same price.\n";
    }
}