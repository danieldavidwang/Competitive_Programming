#include <iostream>
using namespace std;
int t, e, p;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    double pp = 1; cin >> t;
    while (t--) { cin >> e >> p; pp *= static_cast<double>(p-e) / p; }
    cout << pp << '\n';
    return 0;
}