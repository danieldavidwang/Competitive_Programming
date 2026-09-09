#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
char c; int l, n, arr[MM]; double long cur, dis, high = -1e19, low = 1e19;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> l >> n;
    for (int i = 0; i < n; i++) { cin >> arr[i] >> c; }
    sort(arr, arr+n);
    double mid = 2.0*l / n;

    for (int i = 0; i < n; i += 2, cur += mid) {
        dis = arr[i] - cur;
        high = max(dis, high);
        low = min(dis, low);
    }
    for (int i = n-1 - (n&1); ~i; i -= 2, cur += mid) {
        dis = 2*l - arr[i] - cur;
        high = max(dis, high);
        low = min(dis, low);
    }
    cout << fixed << setprecision(10) << (high-low) / 2;
}