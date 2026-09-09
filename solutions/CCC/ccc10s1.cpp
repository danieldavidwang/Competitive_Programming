#include <bits/stdc++.h>
using namespace std;
int n;

struct item {
    string name;
    int r, s, d;
};

bool cmp(item x, item y) {
   int vx = 2*x.r + 3*x.s + x.d, vy = 2*y.r + 3*y.s + y.d;
   if (vy != vx) return vx > vy;
   return x.name < y.name;
}

int main() {
    cin >> n;
    vector<item> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].name >> a[i].r >> a[i].s >> a[i].d;
    }
    sort(a.begin(), a.end(), cmp);
    if (!a.empty()) cout << a[0].name << '\n';
    if (a.size() >= 2) cout << a[1].name << '\n';
}