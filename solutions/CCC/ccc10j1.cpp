#include <bits/stdc++.h>
using namespace std;
int N, ans = 0;

int main() {
    cin >> N;
    int p1 = 0; int p2 = N-p1;
    while(p2 >= p1) {
        if (p1 <= 5 && p2 <= 5)
            ans++;
        p1++;
        p2--;
    }
    cout << ans << '\n';
}