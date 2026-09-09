#pragma GCC optimize (2)
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n, m;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    const int N = n + m; vector<int> arr(N);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    for (int i = n; i < N; ++i) { cin >> arr[i]; arr[i] *= -1; }
    map<long long, int> mp;
    int p1 = (N) / 2; int p2 = (N + 1) / 2;

    for (int mask = 0; mask < (1 << p1); ++mask) {
        long long s = 0;
        for (int bit = 0; bit < p1; ++bit) {
            if (mask & (1 << bit)) s += arr[bit];
        }
        mp[s]++;
    }

    long long ans = -1;

    for (int mask = 0; mask < (1 << p2); ++mask) {
        long long s = 0;
        for (int bit = 0; bit < p2; ++bit) if (mask & (1 << bit)) s += arr[p1+bit];
        ans += mp[-s];
    }

    cout << ans << '\n';
    return 0;
}