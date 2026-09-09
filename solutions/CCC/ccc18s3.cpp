#include <bits/stdc++.h>
using namespace std;
const int MM = 1e2+2;
typedef pair<int, int> pii;
int N, M, dis[MM][MM], dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
char grid[MM][MM];
bool vis[MM][MM];
pii st; vector<pii> cam;
priority_queue<array<int, 3>> pq;

void push(int r, int c, int d) {
    if (grid[r][c] != 'W' && !vis[r][c] && dis[r][c] > d) {
            pq.push({-d, r, c}); dis[r][c] = d;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') st = {i, j};
            if (grid[i][j] == 'C') cam.push_back({i, j});
        }
    }
    
    for (auto e: cam) {
        for (int k = 0; k < 4; k++) {
            int r = e.first, c = e.second;
            while (grid[r][c] != 'W'){
                if (grid[r][c] == '.' || grid[r][c] == 'S') vis[r][c] = true;
                r += dir[k][0]; c += dir[k][1];
            }
        }
    }
    
    memset(dis, 0x3f, sizeof(dis));
    if (!vis[st.first][st.second]) { pq.push({0, st.first, st.second});  dis[st.first][st.second] = 0;}
    
    while (!pq.empty()) {
        auto [d, r, c] = pq.top(); pq.pop();  d = -d;
        if (d > dis[r][c]) continue;
        if (grid[r][c] == '.' || grid[r][c] == 'S') {
            for (int k=0; k<4; k++)
                push (r + dir[k][0], c + dir[k][1], dis[r][c]+1);
        }
        else if (grid[r][c] == 'L') push(r, c-1, dis[r][c]);
        else if (grid[r][c] == 'R') push(r, c+1, dis[r][c]);
        else if (grid[r][c] == 'U') push(r-1, c, dis[r][c]);
        else if (grid[r][c] == 'D') push(r+1, c, dis[r][c]);
    }
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (grid[i][j] == '.') cout << (dis[i][j] == 0x3f3f3f3f ? -1: dis[i][j]) << '\n';
}