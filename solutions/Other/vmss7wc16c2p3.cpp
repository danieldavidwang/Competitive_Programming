#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+6;
int N, M, idx[MM];
vector<int> lis;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1, x; i <= N; i++) { cin >> x; idx[x] = i; }
    cin >> M;
    for (int i = 1, x, y; i <= M; i++) {
        cin >> x;
        y = idx[x];
        if (!y) continue;
        if (lis.empty() || y > lis.back()) lis.push_back(y);
        else *lower_bound(lis.begin(), lis.end(), y) = y;
    }
    cout << lis.size() << '\n';
}