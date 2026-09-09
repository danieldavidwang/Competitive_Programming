#include <bits/stdc++.h>
using namespace std;
const int MM = 3e2+2;
double dp[MM][MM][MM];
int N, arr[4], vis[MM][MM][MM];

double solve(int x, int y, int z) {
    if (vis[x][y][z]) return dp[x][y][z];
    else vis[x][y][z] = 1;
    if (!x && !y && !z) return dp[x][y][z] = 0;
    int ssum = x+y+z; double change = (double) ssum, tot = (N - ssum) / change;

    if (x) tot += ((solve(x-1, y, z) + 1) / change) * x;
    if (y) tot += ((solve(x+1, y-1, z) + 1) / change) * y;
    if (z) tot += ((solve(x, y+1, z-1) + 1) / change) * z;

    return dp[x][y][z] = tot;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1, x; i <= N; i++) { cin >> x; arr[x]++; }
    printf("%.10lf\n", solve(arr[1], arr[2], arr[3]));
}