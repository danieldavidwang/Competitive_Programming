#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>

using namespace std;

long long max1 = 0, max2 = 0;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    
    for (int i = 0; i < N; i++) {
        max1 = 0;
        string x; cin >> x;
        for(int j = 0; j < x.length(); j++) {
            int y = int(x[j]-48);
            if (y % 2 == 0) continue;
            else {
                max1 += y;
            }
        }
        if (max1 > max2) max2 = max1;
    }
    cout << max2;
}