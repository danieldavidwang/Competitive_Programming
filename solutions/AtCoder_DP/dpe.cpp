#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
int N, W;
long long dp[MM];

int main() {
    scanf("%d%d", &N, &W);
    fill(dp, dp+MM, INT_MAX);
    dp[0] = 0;
    
    for(int i = 1, w, val; i <= N; i++) {
        scanf("%d%d", &w, &val);
        for(int j = MM-1; j >= val; j--) {
            dp[j] = min(dp[j], dp[j-val] + w);
        }
    }
    
    for (int i = MM-1; i >= 0; i--) { if(dp[i] <= W) { cout << i << '\n';  return 0; } }
}