#include <bits/stdc++.h>
using namespace std;
long long N, cnt = 0;

int main() {
    cin >> N;
    while (N != 1) {
        if (N%2 == 1) N = 3*N+1;
        else N /= 2;
        cnt++;
    }
    cout << cnt << '\n';
}