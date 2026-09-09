#include <stdio.h>
int a, curr;

int main() {
    scanf("%d", &a);
    while (1) {
        scanf("%d", &curr);
        if (a > curr) a += curr;
        else break;
    }
    printf("%d\n", a);
}