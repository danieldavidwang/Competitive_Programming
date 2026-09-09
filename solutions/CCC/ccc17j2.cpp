#pragma GCC optimize(2)

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, k;
    int shiftSum = 0;

    cin >> N;
    cin >> k;

    for(int i = 0; i < k + 1; i++) {
        shiftSum = shiftSum + N;
        N = N * 10;
    }
    cout << shiftSum;
    return 0;
}