#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    float a, b; cin >> a >> b;
    
    float x = pow(a, 1.0/6);
    float y = pow(b, 1.0/6);
    
    x = ceil(x);
    y = floor(y);
    
    cout << (y-x)+1;
}