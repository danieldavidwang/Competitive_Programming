#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj(10);
int n;

int search(int u) {
    int res = 1;
    for (auto &x : adj[u]) res *= (search(x)+1);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    adj.resize(n + 1);
    for (int x = 1, a; x < n; x++) {
        cin >> a;
        adj[a].push_back(x);
    }
    cout << search(n) << '\n';
    return 0;
}