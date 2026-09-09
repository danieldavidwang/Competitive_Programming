#include <bits/stdc++.h>
using namespace std;
int N, M, total, minn = INT_MAX, idx;

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        total = 0;
        for (int j = 0; j < M; j++) {
            int x; cin >> x;
            if (x == 1 || x == 10) { total++; }
        }
        if (total == 0) { cout << i << '\n'; return 0; }
        else if (total < minn) { idx = i; minn = total; }
    }
    cout << idx << '\n';
}