#include <stdio.h>
int ans = 0, n;

int main() {
    scanf("%d", &n);
    for (int i=2; i<=n-2; i++) ans += (i-1)*(n-1-i);
    ans *= n;
    ans /= 4;
    printf("%d\n", ans);
}