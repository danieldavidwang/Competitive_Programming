#include <bits/stdc++.h>
using namespace std;
int N, a, b, c, d;

int main() {
    cin >> N;
    while (N--) {
        cin >> a >> b >> c >> d;
        if (a-b >= d && a-c <= d) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}