#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+5;
int n;
ll lft = 0, rgt = 1e18;
vector<int> v(MM);

int find(int n) { return v[n] == n ? n : v[n] = find(v[n]); }

bool good(vector<pair<ll, int>> &arr, ll m) {
    iota(v.begin(), v.end(), 0);
    for (int x = 1; x < arr.size(); x++) if (arr[x].first - arr[x-1].first <= m) v[find(arr[x].second)] = find(arr[x-1].second);
    for (int x = 0; x < arr.size(); x++) if (find(x) != find(arr[x].second)) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    vector<pair<ll, int> > arr(n);
    for (int x = 0; x < n; x++) cin >> arr[x].first, arr[x].second = x;
    sort(arr.begin(), arr.end());
    while (lft <= rgt) {
        ll mid = lft+rgt >> 1;
        if (good(arr, mid)) rgt = mid-1;
        else lft = mid+1;
    }
    cout << lft << '\n'; return 0;
}