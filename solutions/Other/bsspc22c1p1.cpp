#include <bits/stdc++.h>
using namespace std;
int N, x, sum = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        sum += x;
        cout << sum << '\n';
    }
}