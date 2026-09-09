#include <stdio.h>
long long n, t1 = 1, t2 = 1, r = 1;
int main() {
    scanf("%lld", &n);
    while (1) { if (t1 <= n && n <= t2) break; t1 += r; r++; t2 += r; }
    printf("%lld\n", (t1+t2)*r/2);
}