#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int S, K; cin >> S >> K;
    
    if (S*S > 3.14*K*K) cout << "SQUARE";
    else cout << "CIRCLE";
}