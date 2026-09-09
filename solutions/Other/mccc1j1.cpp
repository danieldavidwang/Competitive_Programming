#include <bits/stdc++.h>
using namespace std;
int minn = 1e3+1, maxx = 0, w, x, y, z;

int main() {
    cin >> w >> x >> y >> z;
    cout << min(min(x,y), min(w,z)) << '\n' << max(max(x,y), max(w,z)) << '\n';
}