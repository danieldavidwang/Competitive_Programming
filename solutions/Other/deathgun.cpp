#include <bits/stdc++.h>
using namespace std;
const int MM = 2e3+3;
int M, in[MM], idx;
string s1, s2;
vector<string> name;
map<string, int> mp;
vector<int> adj[MM], ord;

int main() {
    cin >> M;
    for (int i = 1; i <= M; i++) {
        cin >> s1 >> s2;
        if (!mp.count(s1)) { mp[s1] = idx++; name.push_back(s1); }
        if (!mp.count(s2)) { mp[s2] = idx++; name.push_back(s2); }
        adj[mp[s2]].push_back(mp[s1]); in[mp[s1]]++;
    }
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < idx; i++) if (in[i] == 0) pq.push(i);

    while (!pq.empty()) {
        int u = pq.top(); pq.pop();
        ord.push_back(u);
        for (int v : adj[u]) if (--in[v] == 0) pq.push(v);
    }
    for (int x : ord) cout << name[x] << '\n';
}