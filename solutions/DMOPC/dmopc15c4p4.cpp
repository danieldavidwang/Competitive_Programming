#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int N, K, Q, a, b, x, y, sequence[MM], psa[MM+1];
unordered_map<int, vector<int> > indicies;

void solve_psa() {
    psa[0] = sequence[0];
    for (int i = 1; i < N; i++) {
        psa[i] = psa[i-1] + sequence[i]; 
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K >> Q;
    
    for (int i = 0; i < N; i++) {
        cin >> sequence[i];
        indicies[sequence[i]].push_back(i+1);
    }
    
    solve_psa();
    
    while (Q--) {
        int sum = 0;
        cin >> a >> b >> x >> y;
        
        if ((indicies[a].size() == 0) || (indicies[b].size() == 0)) {
            cout << "No\n";
            continue;
        }
        
        if (x == 1) sum = psa[y-1];
        else if (x >= 2) sum = psa[y-1] - psa[x-2];

        if ((sum>K) && (upper_bound(indicies[a].begin(), indicies[a].end(), y)-lower_bound(indicies[a].begin(), indicies[a].end(), x)>0) && (upper_bound(indicies[b].begin(), indicies[b].end(), y)-lower_bound(indicies[b].begin(), indicies[b].end(), x)>0)) cout << "Yes\n";
        else cout << "No\n";
    }
}