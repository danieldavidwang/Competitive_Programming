#include <bits/stdc++.h>
using namespace std;
const int MM = 5e3+3;
int T, N, s1, s2, id[MM], t[MM];
bool dp[MM], f[MM];

int main() {
    cin >> T >> N;
    dp[0] = 1; int a = T;
    for (int i = 1; i <= N; i++) {
        cin >> t[i];
        for (int j = T; j >= t[i]; j--)
            if (!dp[j] && dp[j-t[i]]) { id[j] = i; dp[j] = true; }
    }
    for (a = T; !dp[a]; a--);
    for (int p = id[a]; p; a -= t[p], p = id[a]) f[p] = true;
    for (int i = 1; i <= N; i++) {
        if (f[i]) { cout << s1 << " "; s1 += t[i]; }
        else { cout << s2 << " "; s2 += t[i]; }
    }
    cout << '\n';
}