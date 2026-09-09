#include <bits/stdc++.h>
using namespace std;
int N;
int a, b;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        a %= 100; b %= 100;
        if (a == 17 || b == 17) {
            cout << "NO\n";
        } else if ((a == 7 && b == 11) || (a == 11 && b == 7)) {
            cout << "YES\n";
        } else {
            if (a != 11) a %= 10;
            if (b != 11) b %= 10;
            if ((a == 7 && b == 11) || (a == 11 && b == 7)) {
                cout << "YES\n";
            }
            else cout << "NO\n";
        }
    }
}