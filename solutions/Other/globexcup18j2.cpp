#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int N; double avg, cnt;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N; double eval[N];
    for (int i = 0; i < N; i++) {
        cin >> eval[i];
        avg += eval[i];
    }
    avg /= N;
    sort(eval, eval + N, greater<int>());
    if (eval[N/2] > avg) cout << "Winnie should take the risk\n";
    else cout << "That's too risky\n";
    return 0;
}