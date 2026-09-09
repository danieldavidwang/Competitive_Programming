#include <bits/stdc++.h>
using namespace std;
int n, x;
vector<int> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> x; v.push_back(x); }
    sort(v.begin(), v.end(), greater<int>());
    cout << v[n/2] << '\n';
}