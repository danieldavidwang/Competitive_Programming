#include <stdio.h>
long T, A, B, C, D;

int main() {
    scanf("%ld", &T);
    while (T--) {
        scanf("%ld%ld%ld%ld", &A, &B, &C, &D);
        if (((B-A)*(D-C)) > A*C) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}