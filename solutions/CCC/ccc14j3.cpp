#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int a = 100, d = 100, r;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> r;
    for (int i = 0, x, y; i < r; i++) {
        cin >> x >> y;
        if (x > y) d -= x;
        else if (x < y) a -= y;
    }
    printf("%d\n%d\n", a, d);
}