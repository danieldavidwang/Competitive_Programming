#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, lft, rgt;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; rgt = n-1;
    while (lft <= rgt) {
        ll mid = (lft+rgt) >> 1;
        if ((n+mid-1) * (n-mid) < (n-1)*(n)/2) rgt = mid-1;
        else lft = mid+1;
    }
    cout << n-rgt << '\n';
}