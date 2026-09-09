#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int maxV = 3e6+9;
int par[maxV];
map<string, int> person;

int findPair (int x) {
    if (x == par[x]) return x;
    return par[x] = findPair(par[x]);
}

void join (string a, string b) {
    int f = findPair(person[a]);
    int s = findPair(person[b]);
    par[f]=s; 
}

bool check (string a, string b) {
    int f = findPair(person[a]);
    int s = findPair(person[b]);
    if (f == s) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int count = 1;

    for (int i = 0; i <= 1000000; i++) {
        par[i] = i;
    }

    int n; cin >> n;
    vector<pair<string, string>> v(n);
    for (auto &x: v) {
        cin>>x.first>>x.second; 
        if (person[x.first]==0) person[x.first] = count++; 
        if (person[x.second]==0) person[x.second] = count++;
    }

    int m; cin >> m; 
    vector<pair<string, string>> v1(m);
    for (auto &x: v1) {
        cin>>x.first>>x.second;
        if (person[x.first]==0) person[x.first] = count++; 
        if (person[x.second]==0) person[x.second] = count++;
    }

    int g ; cin >> g;
    while (g--) {
        string a, b, c; cin >> a >> b >> c;
        if(person[a]==0) person[a] = count++; 
        if(person[b]==0) person[b] = count++;
        if(person[c]==0) person[c] = count++; 
        join(a, b);
        join(b, c);
    }

    int ans=0; 
    
    for(auto &x: v) {
        ans += check(x.first, x.second);
    }
    for(auto &x: v1) {
        if (check(x.first, x.second) == 0) ans++; 
    }
    cout<<ans<<'\n';
}