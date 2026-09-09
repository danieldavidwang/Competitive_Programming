#include <stdio.h>
int a, ans;

int main() {
    scanf("%d", &a);
    ans += (3*a);
    scanf("%d", &a);
    ans += (4*a);
    scanf("%d", &a);
    ans += (5*a);
    printf("%d\n", ans);
}