#pragma GCC optimize (2)
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<vector<int>> matrix(3, vector<int>(2));
    for (auto &row : matrix) for (auto &element : row) cin >> element;

    for (int row = 0; row < 3; ++row) {
        int firstRow = (row + 1) % 3;
        int secondRow = (row + 2) % 3;

        for (int column = 0; column < 2; ++column) {
            for (int f = 0; f < 2; ++f) {
                for (int s = 0; s < 2; ++s) {
                    if (matrix[firstRow][f] == matrix[secondRow][s] &&
                        matrix[firstRow][1 - f] + matrix[secondRow][1 - s] == matrix[row][column] &&
                        matrix[firstRow][f] + matrix[row][1 - column] == matrix[row][column]) {
                        cout << "YES\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "NO\n";
    return 0;
}