#include <stdio.h>
unsigned long long q, a, b, c;
 
int main() {
    scanf("%lld", &q);
    for (int i = 0; i < q; i++) {
        scanf("%lld%lld%lld", &a, &b, &c);
        printf("%lld\n", a*b+(c%a));
    }
    return 0;
}