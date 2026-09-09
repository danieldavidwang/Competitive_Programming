#include <bits/stdc++.h>
using namespace std;
int n, t, ans = 0;
vector<pair<int, int>> tree, tree2;
bool gud (int x, int minn, int maxx) { return (x>minn && x<maxx); }
bool compare (pair<int, int> a, pair<int, int> b) { return a.second<b.second; }

int checker(vector<pair<int, int>> &tree, int minn, int maxx, int t, int n){
    int temp = 0; bool vis = false;
    vector<int> v = {0};
    for (int i=0; i<tree.size(); i++)
        if(gud(tree[i].first, minn, maxx)) v.push_back(tree[i].second);
        
    v.push_back(n+1);
    for (int i=1; i<v.size(); i++)
        temp = max(temp, v[i] - v[i-1] - 1);
    return temp;
}

int main() {
    cin >> n >> t;
    for (int i = 0, r, c; i<t; i++) {
        cin >> r >> c;
        tree.push_back({r, c});
    }
    
    tree.push_back({0, 0}); tree.push_back({n+1, n+1});
    tree2 = tree;
    sort(tree.begin(), tree.end());
    sort(tree2.begin(), tree2.end(), compare);
    for (int i=0; i<tree.size(); i++) {
        for (int j=i+1; j<tree.size(); j++) {
            int minn = tree[i].first, maxx = tree[j].first;
            ans = max(ans, min(maxx-minn-1, checker(tree2, minn, maxx, t, n)));
        }
    }
    cout << ans << '\n';
}