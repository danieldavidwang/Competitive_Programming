#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
ll N, M, K, arr[MM], temp[MM], diff, cnt, lft = 1, rgt = 2e9+9;

bool check(ll n) {
    cnt = 0;
    for (int i = 1; i <= N; i++) temp[i] = arr[i] - arr[i-1];
    for (int i = 1; i <= N; i++) {
        temp[i] += temp[i-1];
        if ((n-temp[i]) > 0) {
            diff = n-temp[i];
            cnt += diff;
            temp[i] += diff, temp[min(i+M, 1+N)] -= diff;
        }
    }
    return K >= cnt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    while (lft < rgt) {
        ll mid = (lft+rgt) / 2;
        if (check(mid)) lft = mid+1;
        else rgt = mid;
    }
    cout << lft-1 << '\n'; return 0;
}