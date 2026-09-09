#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3;
int N, sum = 0, dp[MM*MM/2], a[MM];

int main() {
    scanf("%d", &N);
    for (int i = 1, x; i <= N; i++) { scanf("%d", &x); a[i] = x; sum += x; }
    dp[0] = 1; int half = ceil(sum/2);
    
    for (int i = 1; i <= N; i++)
        for (int j = half; j >= a[i]; j--)
            if (!dp[j]) dp[j] = dp[j-a[i]];
    
    for (int i = half; i >= 0; i--) if (dp[i]) {
        cout << sum - 2*i << '\n';
        return 0;
    }
}