#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14;
int r, h;
double V;

int main() {
    cin >> r >> h;
    V = pi*r*r*h/3;
    printf("%.2f", V);
}