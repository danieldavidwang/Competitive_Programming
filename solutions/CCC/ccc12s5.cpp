#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int grid[26][26], r, c, k, xCat, yCat;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> r >> c >> k;
    
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            grid[i][j] = 0;
    
    for (int i = 0; i < k; i++) {
        cin >> xCat >> yCat;
        grid[xCat][yCat] = -1;
    }
    for (int i = 1; i <= r; i++) {
        if (grid[i][1] == -1) break;
        grid[i][1] = 1;
    }
    for (int j = 1; j <= c; j++) {
        if (grid[1][j] == -1) break;
        grid[1][j] = 1;
    }
    for (int i = 2; i <= r; i++) {
        for (int j = 2; j <= c; j++) {
            if (grid[i][j] == -1) continue;
            if (grid[i-1][j] != -1 && grid[i][j-1] != -1) grid[i][j] = grid[i-1][j] + grid[i][j-1];
			else if (grid[i-1][j] != -1 && grid[i][j-1] == -1) grid[i][j] = grid[i-1][j];
			else if (grid[i][j-1] != -1 && grid[i-1][j] == -1) grid[i][j] = grid[i][j-1];
			else continue;
        }
    }
    cout << grid[r][c] << '\n';
}