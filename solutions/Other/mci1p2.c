#include <stdio.h>
int r, c;

int main() {
    scanf("%d%d", &r, &c);
    int ans = (r+c)%2;
    if (ans) {
        printf("black\n");
    } else {
        printf("white\n");
    }
}