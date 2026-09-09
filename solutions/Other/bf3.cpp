#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>

using namespace std;

long findNext(long a) {
    if (a == 1) {
        return 2;
    } for (long i = 2; i*i <= a; i++) {
        if (a%i == 0) {
            a += 1; return findNext(a);
        }
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    long N; cin >> N;
    
    long x = findNext(N);
    cout << x;
    
    return 0;
}