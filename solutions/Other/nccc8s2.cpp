#include <bits/stdc++.h>
using namespace std;
typedef long long ll; const ll MOD = 1e9+7; ll result = 1;
string in;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> in;

    for (char c = 'a'; c <= 'z'; c++) {
        ll charFrequency = count(in.begin(), in.end(), c);
        result = (result * (charFrequency + 1)) % MOD;
        in.erase(remove(in.begin(), in.end(), c), in.end());
    }

    cout << result-- << '\n';
    return 0;
}