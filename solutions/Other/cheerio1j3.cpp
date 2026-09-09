#include <bits/stdc++.h>
using namespace std;
const int MM = 2e3+3;
int N, num[MM];
char grid[MM][MM];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        int temp = 0;
        for (int j = N-1; j >= 0; j--) {
            if (grid[j][i] == 'S') temp++;
        }
        num[i] = temp;
    }
    
    for (int i = 0; i < N; i++) {
        int x = N-num[i];
        for (int j = N-1; j >= 0; j--) {
            if (j >= x) grid[j][i] = 'S';
            else grid[j][i] = '.';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
}