#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3+5;
int N, M;
char room[MM][MM];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    if (N == 1) {
        string s; cin >> s;
        for (int i = 0; i < M; i++) {
            if (i >= 1 && s[i] == 'W' && s[i-1] != 'W') { s[i-1] = 'C'; }
            if (i <= (M-1) && s[i] == 'W' && s[i+1] != 'W') { s[i+1] = 'C'; }
        }
        cout << s << '\n';
        return 0;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> room[i][j];
        }
    }
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (room[i][j] == 'W') {
                for(int k=0; k < 4; k++) {
                    int nr = i + dir[k][0], nc = j + dir[k][1];
                    if (nr < 1 || nc < 1 || nr > N || nc > M) continue;
                    if (room[nr][nc] != 'W') room[nr][nc] = 'C';
                }
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << room[i][j];
        }
        cout << endl;
    }
    cout << endl;
}