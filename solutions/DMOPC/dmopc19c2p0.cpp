#include <stdio.h>

int main() {
    int N, a, b, ans = 0;
    scanf("%d%d%d", &N, &a, &b);
    for (int i = 0, x; i < N; i++) {
        scanf("%d", &x);
        if (x >= a && x <= b) ans++;
    }
    printf("%d\n", ans);
}