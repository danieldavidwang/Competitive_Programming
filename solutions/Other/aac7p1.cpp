#pragma GCC optimize (2)

#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize (2)

int t;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int w, h; cin >> w >> h;
        if (w == 1) {
            cout << "bad\n";
            continue;
        }
        else if (h == 1) {
            if (w < 7) {
                cout << "bad\n";
                continue;
            }
            else {
                cout << "good\n";
                continue;
            }
        }
        else if (w >= 4 || h >= 4) {
            cout << "good\n";
        }
        else {
            cout << "bad\n";
        }
    }
}