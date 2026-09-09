#include <bits/stdc++.h>
using namespace std;
const int MM = 1e7+6e6+1e4;
int b[MM], cnt[MM], arr[MM], a2[MM], dis[MM];
bool visited[MM];

bool can_escape(int M, int N, vector<vector<int>> v) {
    int c = 0, d = 0, left = 0, right = 1, a = M*N;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++, c++) {
            a2[i*j]++;
            dis[c] = v[i][j];
        }
    }

    for (int i = 1; i <= a; i++) { cnt[i] = a2[i] + cnt[i-1]; a2[i] += cnt[i-1]; }
    
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            arr[a2[i*j]--] = d++;
    
    while (left < right) {
        int u = b[left++], v2 = dis[u];
        if (visited[v2]) continue;
        else visited[v2] = true;
        for (int i = cnt[v2-1]+1; i <= cnt[v2]; i++) b[right++] = arr[i];
    }
    return visited[a];
}