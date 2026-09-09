#pragma GCC optimize (2)
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxx = 3e5+1;
int N, M, val[maxx]; vector<int> adj[maxx];

void dfs(int curr, int mVal) {
    val[curr] = mVal;
    for (int i: adj[curr]) {
        if(!val[i]) dfs(i, mVal);
    }
}

int main() {
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 1, x, y; i < M+1; i++) {cin >> x >> y; adj[y].push_back(x);}
    for (int i = N; i > 0; i--) {if (!val[i]) dfs(i,i);}
    for (int i = N; i > 0; i--) {
        if (val[i] > i) {
            cout << i << " " << val[i] << "\n";
            return 0;
        }
    }
    cout << "-1\n";
}