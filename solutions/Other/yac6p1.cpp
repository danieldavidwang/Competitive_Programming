#include <bits/stdc++.h>
using namespace std;
int N, M, cnt, maxx;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    maxx = N; cnt = M;
    
    if (M+1 == N) {
        for (int i = 1; i < N; i++) {
            cout << i << " " << maxx << '\n';
        }
        return 0;
    }
    else {
        for (int i = 1; i < N; i++) {
            cout << i << " " << maxx << '\n';
        }
        cnt -= (N-1);
        for (int i = 1; i <= M; i++) {
            if (cnt == 0) return 0;
            for (int j = i+1; j <= N-1; j++) {
                if (cnt == 0) return 0;
                cout << i << " " << j << '\n';
                cnt--;
            }
        }
    }
}