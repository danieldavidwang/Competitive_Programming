#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<vector<string>> grid;
        vector<vector<int>> res;
        vector<pair<int, int>> gud;
        string miss = "X";
        int INF = 1e9;
    void Input() {
       grid = vector<vector<string>>(3, vector<string>(3, ""));
       res = vector<vector<int>>(3, vector<int>(3));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> grid[i][j];
                if (grid[i][j] != miss) {
                    res[i][j] = stoi(grid[i][j]);
                    gud.push_back({i, j});
                }
                else res[i][j] = INF;
            }
        }
    }
    bool checkR(int index) {
        int &a = res[index][0], &b = res[index][1], &c = res[index][2];
        if (b == INF && a < INF && c < INF) {
            b = (a + c) / 2;
            return true;
        }
        if (a == INF && b < INF && c < INF) {
            a = 2 * b - c;
            return true;
        }
        if (c == INF && a < INF && b < INF) {
            c = 2 * b - a;
            return true;
        }
        return a < INF && b < INF && c < INF && a - b == b - c;
    }
    bool checkC(int index) {
        int &a = res[0][index], &b = res[1][index], &c = res[2][index];
        if (b == INF && a < INF && c < INF) {
            b = (a + c) / 2;
            return true;
        }
        if (a == INF && b < INF && c < INF) {
            a = 2 * b - c;
            return true;
        }
        if (c == INF && a < INF && b < INF) {
            c = 2 * b - a;
            return true;
        }
        return a < INF && b < INF && c < INF && a - b == b - c;
    }
    bool fix() {
        set<int> colgud, rowgud;
        for (int i = 0; i < 9; i++) {
            for (int it = 0; it < 3; it++) {
                if (checkR(it)) rowgud.insert(it);
                if (checkC(it)) colgud.insert(it);
            }
        }
        if (colgud.size() == 3 || rowgud.size() == 3) return true;
        return false;
    }
    bool run() {
        if (fix()) return print();
        if (gud.size() == 0 || gud.size() == 1) {
            int d = (gud.size() == 1 ? res[gud[0].first][gud[0].second] : 0);
            res[0][0] = d, res[0][2] = d, res[2][0] = d, res[2][2] = d;
            fix();
            return print();
        } if (gud.size() == 2) {
            int x0 = gud[0].first, y0 = gud[0].second, x1 = gud[1].first, y1 = gud[1].second;
            if (x0 != x1 && y0 != y1) {
                if (abs(x0 - x1) < abs(y0 - y1)) {
                    res[x0][(y0 + 1) % 3] = res[x0][y0], res[x0][(y0 + 2) % 3] = res[x0][y0];
                    res[x1][(y1 + 1) % 3] = res[x1][y1], res[x1][(y1 + 2) % 3] = res[x1][y1];
                } else {
                    res[(x0 + 1) % 3][y0] = res[x0][y0], res[(x0 + 2) % 3][y0] = res[x0][y0];
                    res[(x1 + 1) % 3][y1] = res[x1][y1], res[(x1 + 2) % 3][y1] = res[x1][y1];
                }
            } else {
                for (int i = 0; i < 3; i++) {
                    if (checkR(i)) {
                        res[(i + 1) % 3] = res[i];
                        res[(i + 2) % 3] = res[i];
                        break;
                    }
                    if (checkC(i)) {
                        for (int j = 0; j < 3; j++) res[j][(i + 1) % 3] = res[j][i], res[j][(i + 2) % 3] = res[j][i];
                        break;
                    }
                }
            }
            assert(fix());
            return print();
        } if (gud.size() == 3) {
            int x0 = gud[0].first, y0 = gud[0].second;
            int x1 = gud[1].first, y1 = gud[1].second;
            int x2 = gud[2].first, y2 = gud[2].second;
            if (x0 != x1 && x1 != x2 && x2 != x0 && y0 != y1 && y1 != y2 && y2 != y0) {
                if (res[1][1] < INF) res[1][0] = res[1][1];
                else if (res[0][1] < INF) res[1][1] = res[0][1];
                else if (res[1][0] < INF) res[1][1] = res[1][0];
                else if (res[2][1] < INF) res[1][1] = res[2][1];
                else if (res[1][2] < INF) res[1][1] = res[1][2];
                fix();
                return print();
            } else if ((x0 == x1 && x1 == x2) || (y0 == y1 && y1 == y2)) {
                for (int i = 0; i < 3; i++) {
                    if (checkR(i)) {
                        res[(i + 1) % 3] = res[i];
                        res[(i + 2) % 3] = res[i];
                        break;
                    } if (checkC(i)) {
                        for (int j = 0; j < 3; j++)
                            res[j][(i + 1) % 3] = res[j][i], res[j][(i + 2) % 3] = res[j][i];
                        break;
                   }
                }
            }
            if (fix()) return print();
        }
        for (int i = 0; i < 3; i++) {
            set<int> col, row;
            for (int j = 0; j < 3; j++) {
                if (checkR(j)) row.insert(j);
                if (checkC(j)) col.insert(j);
            }
            assert(col.size() == 1 && row.size() == 1);
            if (checkR(i)) {
                for (int j = 0; j < 3; j++) {
                    if (res[(i + 1) % 3][j] < INF) {
                        int d = res[i][j] - res[(i + 1) % 3][j];
                        res[(i + 1) % 3][(j + 1) % 3] = res[i][(j + 1) % 3] - d;
                        assert(fix());
                        return print();
                    } if (res[(i + 2) % 3][j] < INF) {
                        int d = res[i][j] - res[(i + 2) % 3][j];
                        res[(i + 2) % 3][(j + 1) % 3] = res[i][(j + 1) % 3] - d;
                        assert(fix());
                        return print();
                    }
                }
            }
        }
        return false;
    }
    bool print() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) cout << res[i][j] << ' ';
            cout << '\n';
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] != miss) assert(stoi(grid[i][j]) == res[i][j]);
                assert(res[i][j] < INF && res[i][j] > -INF);
            }
        }
        return true;
    }
};

int main() {
   Solution sol;
   sol.Input();
   assert(sol.run());
}