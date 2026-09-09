#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int a, b, i = 2, ans = INT_MAX;
vector<int> aFacts;
map<int, int> counter, tot;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> a >> b;

    while (a > 1) {
        if (a % i == 0) {
            aFacts.push_back(i);
            while (a % i == 0) { counter[i]++; a /= i; }
        }
        i++;
    }
    for (int i = 2; i <= b; i++) {
        int curr = i;
        for (int fact : aFacts)
            while (curr % fact == 0) { tot[fact]++; curr /= fact; }
    }
    for (int fact : aFacts) {
        int pos = tot[fact] / counter[fact];
        ans = min(ans, pos);
    }
    
    cout << ans << '\n';
    return 0;
}