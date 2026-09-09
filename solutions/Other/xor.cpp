#pragma GCC optimize (2)

#include <bits/stdc++.h>

using namespace std;

short T;
long long S, F, ans;

long long fXOR(long long n) {
    long long mod = n % 4;
 
    if (mod == 0) return n;
    else if (mod == 1) return 1;
    else if (mod == 2) return n + 1;
    else if (mod == 3) return 0;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    while (T--) {
        cin >> S >> F;
        ans = fXOR(S-1)^fXOR(F);
        cout << ans << '\n';
    }
}