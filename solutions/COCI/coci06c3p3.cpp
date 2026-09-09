#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int gridSize, cnt = 0; vector<pair<int, int>> filledCells;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> gridSize;

    for (int row = 1; row <= gridSize; row++) {
        for (int col = 1; col <= gridSize; col++) {
            char c; cin >> c;
            if (c != '.') filledCells.emplace_back(row, col);
        }
    }

    int filled = filledCells.size();
    for (int i = 0; i < filled; i++) {
        long double y1 = filledCells[i].first, x1 = filledCells[i].second;
        for (int j = i + 1; j < filled; j++) {
            long double y2 = filledCells[j].first, x2 = filledCells[j].second;
            for (int k = j + 1; k < filled; k++) {
                long double y3 = filledCells[k].first, x3 = filledCells[k].second;
                if ((y2 - y1) / (x2 - x1) == (y3 - y2) / (x3 - x2)) cnt++;
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}