#include <stdio.h>
#define MM 1000006
int N, nxt, ans, arr[MM];

int main() {
    scanf("%d", &N);
    nxt = N / 2;
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < (N / 2); i++) {
        if (arr[i] == arr[i + nxt]) ans += 2;
    }
    printf("%d\n", ans);
    return 0;
}