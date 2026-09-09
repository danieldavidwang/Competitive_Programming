#include <bits/stdc++.h>
using namespace std;
const int MM = 1e2;
int N, Q;
string word;
char g[MM][MM];
bool gud = false, vis[MM][MM];

bool fun(int r, int c, int idx) {
    if (idx == word.size()) return true;
    vis[r][c] = true;
    for (int a = -1; a <= 1; a++) {
        for (int b = -1; b <= 1; b++) {
            int nr = r + a, nc = c + b;
            if (nr < 0 || nr >= N || nc < 0 || nc >= N || g[nr][nc] != word[idx] || vis[nr][nc]) continue;
            if (fun(nr, nc, idx+1)) return true;
        }
    }
    vis[r][c] = false;
    return false;
}

int main() {
    cin >> N >> Q;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> g[i][j];
    
    for (int i = 1; i <= Q; i++) {
        cin >> word; gud = false;
        memset(vis, false, sizeof(vis));
        for (int r = 0; r < N && !gud; r++)
            for (int c = 0; c < N && !gud; c++)
                if (g[r][c] == word[0]) gud = fun(r, c, 1);
        if (gud) cout << "good puzzle!\n";
        else cout << "bad puzzle!\n";
    }
}