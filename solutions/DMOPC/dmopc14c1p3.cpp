#pragma GCC optimize (2)
#include <iostream>
#include <iomanip>
using namespace std;
int i, s, sum = 0, a;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> i;

    for (int x = 0; x < i; x++) { cin >> a; sum += a; }
    cin >> s;

    for (int x = 0; x < s; x++) {
        cin >> a;
        sum += a;
        cout << fixed << setprecision(10) << static_cast<long double>(sum) / (i + x + 1) << '\n';
    }

    return 0;
}