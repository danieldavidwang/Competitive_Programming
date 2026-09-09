#include <bits/stdc++.h>
using namespace std;
long long C, N, t1 = 0, t2 = 0;

int main() {
    cin >> C;
    
    while(C--) {
        long long x, y;
        cin >> x >> y;
        if (x*y > t1) t1 = x*y;
    }
    
    cin >> N;
    
    while(N--) {
        long long x, y;
        cin >> x >> y;
        if (x*y > t2) t2 = x*y;
    }
    
    if (t1 > t2) cout << "Casper\n";
    else if (t1 < t2) cout << "Natalie\n";
    else cout << "Tie\n";
}