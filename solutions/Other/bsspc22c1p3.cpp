#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3+1;
int N, M, K, table[MM][MM], seats[MM][MM], r, c, ans = 0; 
pair<int, int> moves[8] = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, 1), make_pair(0,-1), make_pair(-1, 1), make_pair(-1, -1), make_pair(1, -1), make_pair(1, 1)};

void printTable() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << table[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    // cout << "N is:" << N << "\n";
    // cout << "K is:" << K << "\n";
    for (int i = 0; i < K; i++) {
        cin >> r >> c;
        // cout << "i=" << i << "\n";
        for (int j = 0; j < 8; j++) {
            if (r+moves[j].first <= 0 || c+moves[j].second <= 0) continue;
            if (r+moves[j].first > N || c+moves[j].second > M) continue;
            table[r+moves[j].first][c+moves[j].second]++;
        }
        seats[r][c] = 1;
        // printTable();
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (table[i][j] >= 3  && seats[i][j] == 0) ans++;
        }
    }
    cout << ans << '\n';
}