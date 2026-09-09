#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
bool sieved[MM+10];
int N, T;

void sieve() { 
    for (int p = 2; p < MM; p++) {
        if (!sieved[p]) {
            for (int i = 2*p; i < MM; i += p) sieved[i] = true;
        }
    }
}

int main() {
    sieve();
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        if (N == 1) { cout << 0 << '\n'; continue; }
        sieved[N] == true ? cout << 0 << '\n' : cout << 1 << '\n';
    }
}