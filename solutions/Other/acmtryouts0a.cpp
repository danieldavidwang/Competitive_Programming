#include <bits/stdc++.h>
using namespace std;
int T, N, maxx;

int main() {
    cin >> T;
    while(T--) {
        maxx = 0;
        cin >> N;
        for (int i = 0, x; i < N; i++) {
            cin >> x;
            if (x > maxx) maxx = x;
        }
        cout << maxx << '\n';
    }
}