#include <stdio.h>

int main(void) {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; i++) {
        scanf("%d%d", &u, &v);
        (u > v) ? printf("%d %d\n", u, v) : printf("%d %d\n", v, u);
    }
    return 0;
}