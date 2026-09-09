#include <stdio.h>
int h1, w1, h2, w2, comp;

int main() {
    scanf("%d%d%d%d", &h1, & w1, &h2, & w2);
    comp = (h1-1)*w2 - (h2-1)*w1;
    if (comp > 0) printf("1\n");
    else if (comp < 0) printf("2\n");
    else printf("-1\n");
    return 0;
}