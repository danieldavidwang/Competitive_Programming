#include <bits/stdc++.h>
using namespace std;
const int MM = 1e2+1;
int R, C, rooms;
char g[MM][MM];

void dfs(int r, int c) {
    g[r][c]='X';
    if(r-1>=1 && g[r-1][c]=='.') dfs(r-1, c);
    if(r+1<=R && g[r+1][c]=='.') dfs(r+1, c);
    if(c-1>=1 && g[r][c-1]=='.') dfs(r, c-1);
    if(c+1<=C && g[r][c+1]=='.') dfs(r, c+1);
}

int main() {
    cin >> R >> C;
    for (int i=1; i<=R; i++)
        for(int j=1; j<=C; j++)
            cin >> g[i][j];
    for (int i=1; i<=R; i++) {
        for (int j=1; j<=C; j++) {
            if (g[i][j]=='.') {
                rooms++;
                dfs(i, j);
            }
        }
    }
    cout << rooms << '\n';
}