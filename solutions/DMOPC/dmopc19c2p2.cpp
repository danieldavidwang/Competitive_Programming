#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;

struct p {
    int x, y;
    p(int x, int y) : x(x), y(y) {}
};

const int MM = 5e2+2;
int N, M, g[MM][MM], cost[MM][MM];
queue<p> q;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    memset(cost, 0x3f, sizeof(cost));
    memset(g, 0x3f, sizeof(g));
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> g[i][j];

    cost[0][0] = g[0][0];
    q.push(p(0, 0));
    
    while (!q.empty()) {
        p cur = q.front(); q.pop();

        if (cost[cur.x + 1][cur.y] > cost[cur.x][cur.y] + g[cur.x + 1][cur.y]) {
            cost[cur.x + 1][cur.y] = cost[cur.x][cur.y] + g[cur.x + 1][cur.y];
            q.push(p(cur.x + 1, cur.y));
        }

        if (cost[cur.x][cur.y + 1] > cost[cur.x][cur.y] + g[cur.x][cur.y + 1]) {
            cost[cur.x][cur.y + 1] = cost[cur.x][cur.y] + g[cur.x][cur.y + 1];
            q.push(p(cur.x, cur.y + 1));
        }
    }
    cout << cost[N-1][M-1] << '\n';
    return 0;
}