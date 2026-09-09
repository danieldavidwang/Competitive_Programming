#include <stdio.h>

int main() {
    int N, x, res = 0;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &x);
        res ^= x; 
    }
    printf("%d\n", res); 
}