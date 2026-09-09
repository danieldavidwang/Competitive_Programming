#include <bits/stdc++.h>
using namespace std;
float A, B, C, ans=0;

int main() {
    cin >> A >> B >> C;
    ans += (A/40000);
    ans += (B/60000);
    ans += (C/70000);
    ans *= 60;
    printf("%.2f\n", ans);
}