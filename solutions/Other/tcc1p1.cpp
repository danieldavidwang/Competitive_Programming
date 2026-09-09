#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+6;
int N, Ycnt, Ncnt; char arr[MM];
int locY = -1;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c; arr[i] = c;
        if (c == 'Y') {
            locY = i;
            Ycnt++;
        }
        else Ncnt++;
    }
    for (int i = 0; i < locY; i++) if (arr[i] == 'N') { Ycnt++; Ncnt--; }
    if (N/2 < Ycnt) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}