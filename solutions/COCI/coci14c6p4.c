#include <stdio.h>
int n, k;
int min(int a, int b) { if (a > b) return b; return a ; }

int main() {
    scanf("%d%d", &n, &k);
    if ((long long) k*k < n) { printf("-1\n"); return 0; }
    for (int i = k; i <= n+k; i += k) {
        for (int j = min(i, n); j > i-k; j--)
            printf("%d ", j);
    }
    return 0;
}