#pragma GCC optimize (2)
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; long long sum = 0, a;
    cin >> n;
    
    vector<long long> arr(n);
    
    for (auto &x : arr) {
        cin >> x;
        sum += x;
    }
    
    if (sum % n != 0) { cout << "Impossible" << '\n'; return 0; }
    sum /= n; long long ans = 0;
    for (auto &x : arr) if (x > sum) ans += x - sum;
    cout << ans << '\n';
    return 0;
}