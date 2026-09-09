#include <bits/stdc++.h>
using namespace std;
int R, C, N;
char grid[40][40]; bool vis[40][40];
string word;

bool solve(int idx, int r, int c, int dr, int dc) {
    if (idx == word.size()) return 1;
    if (!isupper(word[idx])) return solve(idx+1, r, c, dr, dc);
    if (grid[r][c] != word[idx]) return 0;
    if (solve(idx+1, r+dr, c+dc, dr, dc)) { vis[r][c] = 1; return 1; }
    return 0;
}

int main() {
    for (int t = 5; t > 0; t--) {
        cin >> R >> C;
        memset(grid, 0, sizeof(grid));
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= R; i++) {
            for(int j = 1; j <= C; j++)
                cin >> grid[i][j];
        }
        cin >> N; cin.ignore(1, '\n');
        
        for (int k = 1; k <= N; k++) {
            getline(cin, word);
            for (int i = 1; i <= R; i++) {
                for (int j = 1; j <= C; j++) {
                    if (grid[i][j] != word[0]) continue;
                    for (int dr = -1; dr <= 1; dr++){
                        for (int dc = -1; dc <= 1; dc++) {
                            if (dr == 0 && dc == 0) continue;
                            if (solve(0, i, j, dr, dc)) { goto next; }
                        }
                    }
                }
            }
next:   ;
        }
        for (int i = 1; i <= R; i++)
            for (int j = 1; j <= C; j++)
                if (!vis[i][j]) cout << grid[i][j];
        cout << '\n';
    }
    return 0;
}