#include <bits/stdc++.h>
using namespace std;
int N, M, cnt = 0;
vector<int> adj[10001];
int in[10001];
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0, x, y; i < M; i++) {
        cin >> x >> y; adj[x].push_back(y);
        in[y]++;
    }
    for(int i = 1; i < N+1; i++)
        if(in[i]==0) q.push(i);
    
    while(!q.empty()) {
        int u = q.front(); q.pop();
        cnt++;
        for (int v: adj[u]) {
            in[v]--;
            if(!in[v]) q.push(v);
        }
    }
    cnt == N?cout << "Y\n":cout << "N\n";
}