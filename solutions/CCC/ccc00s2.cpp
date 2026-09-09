#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>

using namespace std;

vector<double> v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    
    while (true) {
        int determine; cin >> determine;
        if (determine == 99) {
            int sn; cin >> sn; 
            double p; cin >> p;
            double diff = v[sn-1]*(p/100);
            v[sn-1] = ((100-p)*(v[sn-1]))/100;
            v.insert(v.begin()+(sn-1), diff);
        } else if (determine == 88) {
            int jn; cin >> jn; 
            v[jn-1] = v[jn-1] + v[jn];
            v.erase(v.begin()+(jn));
        } else {
            break;
        }
    }
    
    for (int i = 0; i < v.size(); i++) {
        cout << round(v[i]) << " ";
    }
}