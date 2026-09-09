#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    if (a == 0) return b;
    return gcd(b%a, a);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long a, b; cin >> a >> b;
    
    long long x = gcd(a, b);
    
    cout << a*b/x;
}