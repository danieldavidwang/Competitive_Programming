#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m, n; cin >> m >> n;

    unordered_map<char, char> mirror = {
        {'0', '0'}, {'1', '1'}, {'8', '8'},
        {'6', '9'}, {'9', '6'}
    };

    int ans = 0;
    for (int num = m; num <= n; ++num) {
        string og = to_string(num);
        string mirrored = og;
        bool gud = 1;

        for (char& digit : mirrored) {
            if (mirror.find(digit) == mirror.end()) {
                gud = 0;
                break;
            }
            digit = mirror[digit];
        }
        reverse(mirrored.begin(), mirrored.end());
        if (gud && og == mirrored) ++ans;
    }
    cout << ans << '\n'; return 0;
}