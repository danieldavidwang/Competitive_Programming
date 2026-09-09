#include <bits/stdc++.h>
using namespace std;
int N, x;

void solve() {
    int binaryNum[32];
    int i = 0;
    
    if (x == 0) { cout << "0000\n"; return; }
    
    while (x > 0) {
        binaryNum[i] = x%2;
        x /= 2;
        i++;
    }

    while (i%4 != 0) {
        binaryNum[i] = 0;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        cout << binaryNum[j];
        if (j%4 == 0) cout << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    while (N--) {
        cin >> x;
        solve();
    }
    return 0;
}