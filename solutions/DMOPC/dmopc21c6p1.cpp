#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+1;
int D;
char X[MM];

int main() {
    cin >> D;
    for (int i = 0; i < D; i++) {
        cin >> X[i];
    }
    for (int i = 0; i < D; i++) {
        if (X[i] < X[i+1]) {
            int p = X[i]; int pp = X[i+1];
            X[i] = pp;
            X[i+1] = p;
            break;
        }
    }
    for (int i = 0; i < D; i++) {
        cout << X[i];
    }
    return 0;
}