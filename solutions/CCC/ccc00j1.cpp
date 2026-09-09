#include <bits/stdc++.h>
using namespace std;
void print(int a) { cout << setw(3) << a; }

int main() {
    int a, b; cin >> a >> b;
    int c = a;
    cout << "Sun Mon Tue Wed Thr Fri Sat\n";
    for (int x = 1; x < c; x++) cout << setw(4) << "";

    for (int x = 1; x <= b; x++) {
        print(x);
        c++;

        if (c == 8 || x == b) {
            cout << '\n';
            c = 1;
        } else {
            cout << " ";
        }
    }
    return 0;
}