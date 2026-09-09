#include <bits/stdc++.h>
using namespace std;
int C, M, dp[1002];

int main(){
    cin >> C >> M;
    
    for(int i = 0, v, w; i < C; i++) {
        cin >> v >> w;
        for(int j = M; j >= w; j--)
            dp[j] = max(dp[j], v+dp[j-w]);
    }
    cout << dp[M] << '\n';
}