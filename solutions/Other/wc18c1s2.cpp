#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int w;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> w;
    for (int i = ('a'-1); i <= 'z'; i++) {
        for (int j = ('a' - (i < 'a' ? 1 : 0)); j <= 'z'; j++) {
            for (int k = 'a'; k <= 'z'; k++) {
                if (i >= 'a') cout << char(i);
                if (j >= 'a') cout << char(j);
                cout << char(k);
                w--;
                if (w) cout << " ";
                else return 0;
            }
        }
    }
}