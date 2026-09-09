#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+6;
int N, a[MM], dp[MM];

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
    memset(dp, 127, sizeof(dp));
    dp[0] = 0;
    dp[1] = a[1];
    dp[2] = (a[1]+a[2]-min(a[1], a[2])/4);
    
    for (int i = 3; i <= N; i++) {
        dp[i] = a[i] + dp[i-1];
        dp[i] = min(dp[i], dp[i-2] + a[i] + a[i-1] - min(a[i-1], a[i])/4);
        dp[i] = min(dp[i], dp[i-3] + a[i] + a[i-1] + a[i-2] - min(a[i-2], min(a[i-1], a[i]))/2);
    }
    printf("%d\n", dp[N]);
    return 0;
}