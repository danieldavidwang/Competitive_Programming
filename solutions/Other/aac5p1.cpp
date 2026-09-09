#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+1;
long long N, evens=0, odds=0;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        long long x; cin >> x;
        if (x%2==0) evens++;
        else odds++;
    }
    cout << evens/2 + odds/2 << '\n';
}