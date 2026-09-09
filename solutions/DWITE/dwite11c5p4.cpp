#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 23;
int N, M, ans, cubes[MM][MM];
bool no[MM][MM];

void floodfill(int a, int b) {
    if (a < 0 || a >= N || b < 0 || b >= M) { return; }
    if (no[a][b]) { return; }
    no[a][b] = true;
    floodfill(a, b-1);
	floodfill(a, b+1);
	floodfill(a-1, b);
	floodfill(a+1, b);
}

int cap(int h) {
    for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			no[i][j] = (cubes[i][j] > h);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i == 0 || i == N-1 || j == 0 || j == M-1) floodfill(i, j);
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (!no[i][j]) cnt++;
	
	return cnt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int k = 0; k < 5; k++) {
        ans = 0; cin >> N >> M;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> cubes[i][j];
            }
        }
        for (int i = 0; i <= 50; i++) ans += cap(i);
        cout << ans << '\n';
    }
}