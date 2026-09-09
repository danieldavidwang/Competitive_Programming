#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int K, N, u;
    cin >> K;
    vector<int> ele(K);
    for (auto &element : ele) cin >> element;
    cin >> N;
    sort(ele.begin(), ele.end());
    while (N--) {
        cin >> u;
        cout << u - (upper_bound(ele.begin(), ele.end(), u) - ele.begin()) << '\n';
    }
    return 0;
}