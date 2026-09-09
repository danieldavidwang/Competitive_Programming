#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 19;
int M, N; string arr1[MM], arr2[MM]; vector<int> ans; unordered_set<string> vis;

vector<int> solve(int n, string str, string str2, vector<int> ret) {
    if (!n) {
        if (str == str2) return ret;
        else { ret.clear(); return ret; }
    }
    
    if (str2 != "" && str == str2) return ret;
    int minN = (int) min(str.length(), str2.length());
    if (str2.substr(0, minN) != str.substr(0, minN)) { ret.clear(); return ret; }
    
    for (int i = 1; i <= N; i++) {
        vector<int> v1 = ret;
        v1.push_back(i);
        vector<int> ans = solve(n-1, str+arr1[i], str2+arr2[i], v1);
        if (!ans.empty()) return ans;
    }
    ret.clear();
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N;
    for (int i = 1; i <= N; i++) cin >> arr1[i];
    for (int i = 1; i <= N; i++) cin >> arr2[i];
    ans = solve(M, "", "", ans);
    
    if (ans.empty()) cout << "No solution.\n";
    else { cout << ans.size() << '\n'; for (int a: ans) cout << a << '\n'; }
    return 0;
}