#pragma GCC optimize (2)

#include <bits/stdc++.h>

using namespace std;

bool check(int a, int b, int c) {
    int area = 1;
    for (int i = 0; i < (a-1); i++) {
        area *= 5;
    }
    int bb = b%area; int cc = c%area;
    b /= area; c /= area;
    
    if (b==0 || b==4) return false;
    if (((b==1) && (c==0)) || ((b==2) && (c == 0)) || ((b==3) && (c==0)) || ((b==2) && (c==1))) return true;
    if (a > 1) {
        if (((b==1) && (c==1)) || ((b==2) && (c==2)) || ((b==3) && (c==1))) return check(a-1, bb, cc);
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    
    for (int i = 0; i < T; i++) {
        int m, x, y; cin >> m >> x >> y;
        if (check(m, x, y)) {cout << "crystal\n";}
        else {cout << "empty\n";}
    }
}