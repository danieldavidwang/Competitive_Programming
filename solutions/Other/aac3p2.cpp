#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int K, D, nums[11], minVal = INT_MAX, minVal2 = INT_MAX;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> K >> D;
    for (int i = 0; i < D; i++) {
        cin >> nums[i];
        if (nums[i] < minVal2) minVal2 = nums[i];
        if (nums[i] < minVal)  {
            minVal2 = minVal;
            minVal = nums[i];
        }
    }

    if (minVal == 0) {
        if (D == 1) {
            cout << "-1\n";
            return 0;
        }
        if (K == 1) cout << minVal2 << '\n';
        else if (K == 2) cout << minVal2 << minVal2 << '\n';
        else {
            for (int i = 0; i < K; i++) {
                if ((i == 0) || (i == K-1)) cout << minVal2;
                else cout << 0;
            }
            cout << '\n';
        }
    } else {
        for (int i = 0; i < K; i++)
            cout << minVal;
        cout << '\n';
    }
}