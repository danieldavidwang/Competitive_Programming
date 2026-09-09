#include <stdio.h>
int N, freq[51], maxV = 0, maxA = 0;

int main() {
    scanf("%d", &N);
    for (int i = 0, x; i < N; i++) {
        scanf("%d", &x); freq[x]++;
    }
    for (int i = 1; i < 51; i++) {
        int res = i*freq[i];
        if (res > maxV) {
            maxV = res;
            maxA = i;
        }
    }
    printf("%d\n", maxA);
}