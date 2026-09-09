#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B, C, D; cin >> A >> B >> C >> D;
    
    bool b1 = false, b2 = false;
    
    if (B > A) b1 = true;
    if (D > C) b2 = true;
    
    if (b1 && b2) cout << "Go to the department store" << '\n';
    else if (b1) cout << "Go to the grocery store" << '\n';
    else if (b2) cout << "Go to the pharmacy" << '\n';
    else cout << "Stay home" << '\n';
}