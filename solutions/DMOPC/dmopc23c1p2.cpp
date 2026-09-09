#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int N;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    if (N%5 == 1) {
        for (int i = 1; i <= N-2; i++) {
            for (int j = 0; j < N; j++) {
                if (i%5 == 3) cout << "1 ";
                else cout << "0 ";
            }
            cout << endl;
        }
        for (int i = 0; i < N; i++) { if (i%5 == 2 || i%5 == 3) cout << "1 "; else cout << "0 "; }
        cout << endl;
        for (int i = 0; i < N; i++) { if (i%5 == 2 || i%5 == 3) cout << "1 "; else cout << "0 "; }
        cout << endl; return 0;
    } else if (N%5 == 2) {
        for (int i = 0; i < N; i++) cout << "1 ";
        cout << endl;
        for (int i = N; i >= 2; i--) {
            for (int j = N; j >= 1; j--) {
                if (i%5 == 3) cout << "1 ";
                else cout << "0 ";
            }
            cout << endl;
        }
        return 0;
    } else {
        for (int i = N; i >= 1; i--) {
            for (int j = N; j >= 1; j--) {
                if (i%5 == 3) cout << "1 ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }
}