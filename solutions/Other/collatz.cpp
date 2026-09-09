#include <bits/stdc++.h>
using namespace std;
int n, cnt = 0;

int main() {
    cin >> n;
    while(n != 1) {
        if (n%2 == 0) n /= 2;
        else n = 3*n+1;
        cnt++;
    }
    cout << cnt << '\n';
}