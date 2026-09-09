#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+4;
int n, scene[MM];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> scene[i];
    for (int i = 0; i < n; i++) {
        if (!scene[i]) for (int j = 1;j <= 4; j++) if ((j != scene[i-1] || !i) && (j != scene[i+1]) || i == n-1) { scene[i] = j; break; }
    }
    for (int i = 0; i < n; i++) cout << scene[i];
    return 0;
}