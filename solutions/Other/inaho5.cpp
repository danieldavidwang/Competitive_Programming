#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
int n; ull ans; ll k;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    while (n--) { cin >> k; ans += -k; }
    if (!ans) cout << 0 << '\n';
    else printf("-%llu\n", ans);
}