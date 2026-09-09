#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const long long MM = 3e3+3;
long long N, tot, board[MM], dp[MM][MM];
bool visited[MM][MM];

long long solveDP(long long x, long long y) {
    if (x > y) return 0;
    else {
        if (!visited[x][y]) {
            visited[x][y] = 1;
            dp[x][y] = max(board[y]+min(solveDP(x+1, y-1), solveDP(x, y-2)), board[x]+min(solveDP(x+1, y-1), solveDP(x+2, y)));
        }
    }
    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) { cin >> board[i]; tot += board[i]; }
    cout << 2*solveDP(0, N-1)-tot << '\n';
    return 0;
}