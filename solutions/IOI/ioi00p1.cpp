#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 5e3+5;
int N, dp[2][MM], pre = 0, curr = 1;
string str;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> str;
    for (int i = N-2; i >= 0; i--){
        for (int j = i+1; j < N; j++) {
            if (str[i] == str[j]) dp[curr][j] = dp[pre][j-1];
            else dp[curr][j] = min(dp[pre][j], dp[curr][j-1]) + 1;
        }
        swap(pre, curr);
    }
    cout << dp[pre][N-1] << '\n';
}