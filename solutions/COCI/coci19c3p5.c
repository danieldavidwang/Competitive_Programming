#include <stdio.h>
int N, M;

int main() {
    scanf("%d%d", &N, &M);
    N -= 1; int pre = M-1;

    while (N >= 0) {
        int curr = pre + 1;
        while ((N & curr) != N) curr++;
        int new_pre = curr;
        while (curr > pre) {
            printf("%d %d\n", N, curr);
            N--;
            curr--;
        }
        pre = new_pre;
    }
    return 0;
}