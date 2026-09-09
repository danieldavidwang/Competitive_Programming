#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3+3;
int r, c, ans = 0, h[MM][MM];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c;

    vector<vector<char>> arr(MM, vector<char>(MM, 'X'));

    for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) cin >> arr[i][j];

    for (int x = r + 1; x >= 0; x--)
        for (int y = 0; y <= c + 1; y++)
            h[x][y] = (arr[x][y] == 'X') ? (0) : (h[x + 1][y]+1);

    for (int x = 0; x <= r + 1; x++) {
        stack<int> ms;
        vector<vector<int>> pos(2, vector<int>(c + 1));

        for (int y = 0; y <= c + 1; y++) {
            while (!ms.empty() && h[x][ms.top()] >= h[x][y]) ms.pop();
            pos[0][y] = ms.empty() ? 0 : ms.top();
            ms.push(y);
        }

        while (!ms.empty()) ms.pop();

        for (int y = c + 1; y >= 0; y--) {
            while (!ms.empty() && h[x][ms.top()] >= h[x][y]) ms.pop();
            pos[1][y] = (ms.empty() ? c + 1 : ms.top()-1);
            ms.push(y);
        }

        for (int y = 0; y <= c + 1; y++) {
            if (!h[x][y]) continue;
            ans = max(ans, 2 * (pos[1][y] - pos[0][y] + h[x][y]));
        }
    }

    cout << (ans-1) << '\n';
    return 0;
}