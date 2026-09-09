#include <bits/stdc++.h>

#define LOOP(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) LOOP(i, 0, n)

using namespace std;

const int MM = 1e7+9;

vector<int> primes;
bool sieved[MM+10];
int A, B, C, D;

void allPrimes() { 
    for (int p = 2; p < MM; p++) {
        if (!sieved[p]) primes.push_back(p);
        for (int i = p; i < MM; i += p) {
            sieved[i] = true;
        }
    }
}

int val(int p, int x) {
    if (x == 0) return 0;
    return x/p + val(p, x/p); 
}

void solve() {
    for (auto p: primes) {
        if (val(p, B) + val(p, C) > val(p, A) + val(p, D)) {
            cout << "NE" << '\n';
            return;
        }
    } 
    cout << "DA" << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    allPrimes();
    int T; cin >> T;
    REP(i, T) {
        cin >> A >> B >> C >> D;
        A--; C--;
        solve();
    }
}