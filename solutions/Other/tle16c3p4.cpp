#include <bits/stdc++.h>
using namespace std;
long long N, M;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    if (N==1 || M==1) {
        cout << "First\n";
        return 0;
    }
    long long p = N+M;
    if (p % 2 == 0) cout << "Second\n";
    else cout << "First\n";
}