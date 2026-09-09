#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>

using namespace std;

int dislikes[101], pizzas[101], arr[101][101];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    
    for (int i = 0; i < n; i++) cin >> dislikes[i];

    int m; cin >> m;
    int ans = m;
    
    for (int i = 0; i < m; i++) {
        cin >> pizzas[i];
        bool good = true;
        for (int j = 0; j < pizzas[i]; j++) {
            cin >> arr[i][j];
            for (int x = 0; x < n; x++)
                if (dislikes[x] == arr[i][j]) {
                    good = false;
                    break;
                }
        }
        if (!good) ans--;
    }
    cout << ans;
}