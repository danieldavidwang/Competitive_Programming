#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define clear(a, b) memset(a, b, sizeof(a))
#define mp(a, b) make_pair((a), (b))
#define all(x) x.begin(),x.end()
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<pii> viii;
const int mod = 1e9+7, MM = 1504;
int N, M, K, g[MM][MM], dis[MM][MM], d[4][2]={{-1,0}, {1,0}, {0,-1}, {0, 1}}; deque<pii> q;
int main(){
    cin >> N >> M >> K;  clear(g, -1);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++){
            cin >> g[i][j];
            if(g[i][j]) q.pb({g[i][j], {i, j}});
        }
    }
    sort(all(q));
    while(!q.empty()){
        auto [dd, e] = q.front(); q.pop_front();
        if(dis[e.f][e.s] >= K) continue;
        for(int k=0; k<4; k++){
            int nr = e.f + d[k][0], nc = e.s + d[k][1];
            if(!g[nr][nc]) { dis[nr][nc] = dis[e.f][e.s]+1; g[nr][nc]=dd; q.pb({dd, {nr, nc}}); }
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cout << g[i][j] << " \n"[j==M];
        }
    }
}