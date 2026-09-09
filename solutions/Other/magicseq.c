#include <stdio.h>

long long addedVal[91];
long long ans[91];

int main() {
    addedVal[0] = 1; addedVal[1] = 2;
    ans[0] = 1;
    
    for (int i = 2; i < 91; i++) {
        addedVal[i] = addedVal[i-1]+addedVal[i-2];
        ans[i-1] = ans[i-2]+addedVal[i-2];
    }
    
    short n; scanf("%hd",&n);
    printf("%lld", ans[n-1]);
}