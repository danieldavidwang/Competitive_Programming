#include <stdio.h>
int N, t, c[2][200005];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < 2; i++)
        for (int j = 1; j <= N; j++)
            scanf("%d", &c[i][j]);
    for (int i = 1; i <= N; i++){
        t += 3*(c[0][i]+c[1][i]);
        if (i%2 && c[0][i] && c[1][i]) t -= 2;
        if (c[0][i-1] && c[0][i]) t -= 2;
        if (c[1][i-1] && c[1][i]) t -= 2;
    }
    printf("%d\n", t);
}