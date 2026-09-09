#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull ans;
ull arr[50];
int zeros;

void solve() {
    arr[0] = 1;
    arr[1] = 1;
    long long mod = 4294967296;
    for (int i = 2; i < 50; i++) {
        arr[i] = arr[i-1] * i % mod;
        if (arr[i] == 0) {
            zeros = i;
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    
    solve();
    
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        if (s.length() >= 3) {
            cout << 0 << '\n';
        } else {
            int x2 = stoi(s);
            if (x2 >= zeros) {
                cout << 0 << '\n';
            }
            else {
                cout << arr[x2] << '\n';
            }
        }
    }
    return 0;
}