#include <bits/stdc++.h>
using namespace std;
int R, C, x, y; set<int> lights[32];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        x = 0, y = 0;
        for (int j = 1; j <= C; j++){
            cin >> y; x = x<<1 | y;
        }
        lights[R-i+1].insert(x);
    }
    for (int i = R-1; i >= 1; i--) {
        int curr = *(lights[i].begin());
        for(int j: lights[i+1]) lights[i].insert(curr^j);
    }
    cout << lights[1].size() << '\n';
}