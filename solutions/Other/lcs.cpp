#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int L[1001][1001], len1, len2, X[1001], Y[1001];

int lcs(int m, int n) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) L[i][j] = 0;
            else if (X[i-1] == Y[j-1]) L[i][j] = L[i-1][j-1] + 1;
            else L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    return L[m][n];
}
  
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> len1 >> len2;
    for (int i = 0; i < len1; i++) cin >> X[i];
    for (int i = 0; i < len2; i++) cin >> Y[i];
    cout << lcs(len1, len2) << '\n';
}