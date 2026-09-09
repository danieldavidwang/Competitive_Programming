#include <stdio.h>
long long n;

int main() {
    scanf("%lld", &n);
    (n-3 > 0) ? printf("%lld\n", n-3): printf("0\n");
}