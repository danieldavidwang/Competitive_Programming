#include <stdio.h>
int N, arr[200005];

int find() {
    for (int i = 1; i <= N; i++) if (arr[i] == N) return i;
    return -1;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
    if (N == 1 || N == 2 || N == 3) { int x = find(); printf("%d %d", x, x); }
    else {
        if (arr[1] == 1) printf("2 %d", N);
        else if (arr[N] == 1) printf("1 %d", (N-1));
        else printf("1 %d", N);
    }
    return 0;
}