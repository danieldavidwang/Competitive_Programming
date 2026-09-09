#include <bits/stdc++.h>
using namespace std;
vector<long long> arr;

long long maxSum(long long N) {
    long long dp[N][2];
    if (N == 1) return arr[0];

    dp[0][0] = 0;
    dp[0][1] = arr[0];
   
    for (long long i = 1; i < N; i++) {
        dp[i][1] = dp[i-1][0] + arr[i];
        dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
    }
    return max(dp[N-1][0], dp[N-1][1]);
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long N; cin >> N;
    
    for (long long i = 0, x; i < N; i++) {
        cin >> x; 
        arr.push_back(x);
    }
    
    long long s = arr.size();
    cout << maxSum(s) << '\n';
    return 0;
}