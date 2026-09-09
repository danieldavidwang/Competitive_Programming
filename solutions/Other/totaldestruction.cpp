#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+6;
int n, m, q, ans, arr[MM]; vector<int> g;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> q;
    for (int i = 0; i < q; i++) cin >> arr[i];
    sort(arr, arr+q);
    ans = (arr[q-1] - arr[0]);
    for (int i = 0; i < q-1; i++) g.push_back(arr[i+1] - arr[i] - 1);
    sort(g.begin(), g.end()); reverse(g.begin(), g.end());
    for (int i = 0; i < m-1; i++) ans -= g[i];
    cout << (ans+1) <<'\n';
    return 0;
}