#include <bits/stdc++.h>
using namespace std;
int N;

int main() {
    cin >> N;
    cout << "1\n";
    for (int i = 2; i <= N; i++) {
        if (N % i == 0) cout << i << '\n';
    }
    return 0;
}