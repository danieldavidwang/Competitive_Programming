#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
bool sieved[MM+10];
int N;
long long sum = 0;

void sieve() { 
    for (int p = 2; p < MM; p++) {
        if (!sieved[p]) {
            for (int i = 2*p; i < MM; i += p) sieved[i] = true;
        }
    }
}

int main() {
    sieve();
    for (int i = 0; i < 5; i++) {
        cin >> N; sum = 0;
        for (int j = 1; j <= N; j++) {
            if (!sieved[j] && j != 1) sum += j;
        }
        cout << sum << '\n';
    }
}