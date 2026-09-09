#include <bits/stdc++.h>
using namespace std;
const int MM = 1e2+2;
int R, C, ans = 0, dir[8][2] = {{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};
string word;
char grid[MM][MM];

void findd(int r, int c, int k, int idx, bool turn) {
    if (idx == word.length()) { ans += 1; return; }
    for (int i = k-2; i <= k+2; i += 2) {
        int nk = (i+8)%8, nr = r+dir[nk][0], nc = c+dir[nk][1];
        if (0 <= nr && nr < R && 0 <= nc && nc < C && grid[nr][nc] == word[idx] && (!turn || nk == k)) findd(nr, nc, nk, idx+1, (turn || nk != k));
    }
}

int main() {
    cin >> word >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == word[0]) {
                for (int k = 0; k < 8; k++) {
                    int nr = i+dir[k][0], nc = j+dir[k][1];
                    if (0 <= nr && 0 <= nc && nr < R && nc < C && grid[nr][nc] == word[1]) {
                        findd(nr, nc, k, 2, false);
                    }
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
    
}