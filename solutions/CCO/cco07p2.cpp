#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int poss = 0, mini, n;
set<vector<int>> sfs, cnt;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> sf(12);
        mini = INT_MAX;
        for (int j = 0; j < 6; j++) {
            cin >> sf[j];
            sf[j+6] = sf[j];
            if (sf[j] < mini) mini = sf[j];
        }
        cnt.clear();
        for (int j = 0; j < 6; j++) {
            if (sf[j] == mini) {
                vector<int> t(6);
                vector<int> rev(6);
                for (int k = j; k < j+6; k++) t[k-j] = sf[k];
                sfs.insert(t);
                for (int k = j+6, w = 0; k > j; k--, w++) rev[w] = sf[k];
                sfs.insert(rev); cnt.insert(t); cnt.insert(rev);
            }
        }
        poss += cnt.size();
    }
    if (sfs.size() == poss) cout << "No two snowflakes are alike.\n";
    else cout << "Twin snowflakes found.\n";
    return 0;
}