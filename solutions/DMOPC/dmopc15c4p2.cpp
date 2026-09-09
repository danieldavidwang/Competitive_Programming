#include <bits/stdc++.h>
using namespace std;
int h, m, n;

int main()  {
    cin >> h >> m >> n;
    m += n%60; h += n/60; h %= 24;
    if (m >= 60) m -= 60, h++, h %= 24;
    cout << h << " " << m << '\n'; return 0;
}