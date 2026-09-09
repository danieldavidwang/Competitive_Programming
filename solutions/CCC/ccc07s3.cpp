#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4;
int N, x, y, sep, assigns[MM];
bool circle[MM];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0, a, b; i < N; i++) {
        cin >> a >> b; assigns[a] = b;
    }
    cin >> x >> y;
    while (!(x == 0 && y == 0)) {
        for (int i = 0; i < MM; i++)
            circle[i] = false;
        sep = -1;
        while (!circle[x] && x != y) {
            circle[x] = true;
            sep++;
            x = assigns[x];
        }
        if (x == y) cout << "Yes " << sep << "\n";
        else cout << "No\n";
        cin >> x >> y;
    }
}