#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5;
vector<int> primes;
bool sieved[MM+10];
int N;

void sieve() { 
    for (int p = 2; p < MM; p++) {
        if (!sieved[p]) primes.push_back(p);
        for (int i = p; i < MM; i += p) sieved[i] = true;
    }
}

int main() {
    cin >> N;
    sieve();
    for (int i = 0; i < N; i++) {if (i%10==0 && i != 0) cout << '\n'; cout << primes[i] << " ";}
    cout << '\n';
}