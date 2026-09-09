#include <bits/stdc++.h>
using namespace std;
char p1[101], p2[101];
int ans = 0, N;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> p1[i];
    for (int i = 0; i < N; i++)
        cin >> p2[i];
    for (int i = 0; i < N; i++) {
        if (p1[i] == 'C' && p2[i] == 'C') {
            ans++;
        }
    }
    cout << ans << '\n';
}