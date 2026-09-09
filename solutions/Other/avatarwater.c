#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a > b) { printf("%d\n", a-b); return 0; }
    else if (b > c) { printf("%d\n", b-c); return 0; }
    else if (b > a) { printf("%d\n", b-a); return 0; }
    else if (c > b) { printf("%d\n", c-b); return 0; }
    else if (a > c) { printf("%d\n", a-c); return 0; }
    else if (c > a) { printf("%d\n", c-a); return 0; }
}