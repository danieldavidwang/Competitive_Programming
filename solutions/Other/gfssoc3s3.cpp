#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9;
long long n, ans = 0;

int main() {
    scanf("%lld", &n);
    if (n <= 16) {
        for (long long i = 0; i < n; i++) {
            ans += 9*pow(10, (i/2));
            ans %= mod;
        }
        printf("%lld\n", ans);
    }
    else (printf("999999998\n"));
}