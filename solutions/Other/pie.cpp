#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    double total = 1;
    
    int N, M; cin >> N; cin >> M;
    double arr[N+2];
    
    int a;
    double p;
    
    for (int i = 1; i < N+1; i++) {
        arr[i] = 0;
    }
    
    for (int i = 0; i < M; i++) {
        cin >> a >> p;
        arr[a] += total*(p/100);
        total = total - total*(p/100);
    }
    for(int i = 1; i < N+1; i++) {
        cout << arr[i] << '\n';
    }
}