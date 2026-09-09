#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int n, pnt, xArr[MM], yArr[MM];
long long ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; pnt = (n-1) / 2;
    for (int i = 0, x, y; i < n; i++) { cin >> x >> y; xArr[i] = x; yArr[i] = y; }
    sort(xArr, xArr + n); sort(yArr, yArr + n);
    int xMid = xArr[pnt], yMid = yArr[pnt];
    for (int i = 0; i < n; i++) ans += abs(xMid-xArr[i]) + abs(yMid-yArr[i]);
    cout << ans << '\n';
}