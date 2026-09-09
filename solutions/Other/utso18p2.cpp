#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int arr[3][3], ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) cin >> arr[i][j];
    for (int i = 0; i < 3; i++) if (arr[1][i] == arr[0][(i+2)%3]) ans = max(ans+arr[2][i], ans);
    cout << ans << '\n';
    return 0;
}