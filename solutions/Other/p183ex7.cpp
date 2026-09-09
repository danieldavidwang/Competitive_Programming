#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
bool sieved[MM];
int N;

void sieve() { 
    sieved[1] = true;
    for (int p = 2; p < MM; p++) {
        if (!sieved[p]) { for (int i = 2*p; i < MM; i += p) sieved[i] = true; }
    }
}

int main() {
    cin >> N;
    sieve();
    for (int i = 1; i <= N; i++) { if (!sieved[i]) cout << "1\n"; else cout << "0\n"; }
    cout << '\n';
}