#pragma GCC optimize (2)
#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    multiset<int> values;
    int distinctCount = 0;

    for (int i = 0; i < n; ++i) {
        int current; cin >> current;
        auto it = values.find(current);
        if (it == values.end()) distinctCount++;
        else values.erase(it);
        values.insert(current-1);
    }
    cout << distinctCount << '\n';
    return 0;
}