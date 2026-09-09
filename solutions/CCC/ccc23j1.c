#include <stdio.h>
int x, y;

int main() {
    scanf("%d%d", &x, &y);
    x > y ? printf("%d\n", 50*x-10*y+500) : printf("%d\n", 50*x-10*y) ;
}