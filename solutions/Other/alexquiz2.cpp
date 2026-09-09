#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>
using namespace std;

const int MM = 1e5+5;
int dp[MM];
int arr[MM + 1];

int A, B;
 
void solve() {
    arr[0] = 1;
    arr[1] = 1;

    for (int i = 2; i <= sqrt(MM); i++) {
        if (arr[i] == 0) {
            for (int j = i * i; j <= MM; j += i) {
                arr[j] = 1;
            }
        }
    }
    long runningPrimeSum = 0;
 
    for (int i = 1; i <= MM; i++)
    {
        if (arr[i] == 0) runningPrimeSum += i;
        dp[i] = runningPrimeSum;
    }
    // return dp[B] - dp[A - 1];
}
 
int main()
{
    int Q; cin >> Q;
    solve();
    for (int i = 0; i < Q; i++) {
        cin >> A >> B;
        long ans = dp[B] - dp[A-1];
        cout << ans << '\n';
    }
    return 0;
}