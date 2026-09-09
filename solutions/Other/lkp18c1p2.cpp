#include <stdio.h>
long long n, p, t;

int main() {
    scanf("%lld", &n);
    p = n/2; t = 2*(p*(p+1));
    if (!(n%2)) t -= n;
    printf("%lld\n", t);
}