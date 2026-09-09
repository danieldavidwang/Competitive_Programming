#include <stdio.h>

int main() {
    int N; scanf("%d", &N);

    while(N--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", a+b);
    }
}