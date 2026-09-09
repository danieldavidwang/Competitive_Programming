#pragma GCC optimize (2)
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> bit(2, vector<int>(500050));

int queryAndUpdateCount(int n) {
    int sum = 0, sum1 = 0;
    for (int x = n; x > 0; x -= x & -x) sum += bit[0][x];
    for (int x = bit[0].size() - n; x > 0; x -= x & -x) sum1 += bit[1][x];
    return min(sum, sum1);
}

void updateBit(int n) {
    for (int x = n; x < bit[1].size(); x += x & -x) bit[0][x]++;
    for (int x = bit[1].size() - n; x < bit[1].size(); x += x & -x) bit[1][x]++;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, a; long long s = 0;
    cin >> n;
    
    while (n--) {
        cin >> a;
        s += queryAndUpdateCount(a);
        updateBit(a);
    }
    cout << s;
    return 0;
}