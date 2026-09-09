#include <bits/stdc++.h>
using namespace std;
int a, e;

int main() {
    cin >> a >> e;
    if (a >= 3 && e <= 4) cout << "TroyMartian\n";
    if (a <= 6 && e >= 2) cout << "VladSaturnian\n";
    if (a <= 2 && e <= 3) cout << "GraemeMercurian\n";
    return 0;
}