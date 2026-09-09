#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
const int MM = 2e3+3;
int N, K, g[MM][MM];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    scan(N); scan(K);
    if (!K) { cout << "-1\n"; return 0; }
    else if (K > N) { cout << "-1\n"; return 0; }
    int maxx = N*N;
    for (int i = 0; i < K; i++) { g[i][i] = maxx; maxx--; }
    int curr = N*N-K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j && K) { cout << g[i][j] << " "; K--; }
            else { cout << curr << " "; curr--; }
        }
        cout << '\n';
    }
    return 0;
}