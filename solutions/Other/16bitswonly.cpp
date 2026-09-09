#include <bits/stdc++.h>

using namespace std;

int main() {
    long N; cin >> N;
    
    for (long i = 0; i < N; i++) {
        long A, B, P; cin >> A; cin >> B; cin >> P;
        long result = A*B;
        
        if (result == P) {
            cout << "POSSIBLE DOUBLE SIGMA" << endl;
        } else {
            cout << "16 BIT S/W ONLY" << endl;
        }
    }
}