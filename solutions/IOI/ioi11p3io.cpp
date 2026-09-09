#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
long long leftIndex, rightIndex, frontIndex, backIndex, middleIndex, maxDiff; int X[MM];
vector<long long> q(100010);

int besthub(int num, int length, int elements[], long long maxDifference) {
    long long curDiff = 0;

    while (leftIndex < num && rightIndex < num) {
        while (rightIndex <= num && curDiff <= maxDifference) {
            maxDiff = max(maxDiff, backIndex - frontIndex);
            if (rightIndex < num) {
                if ((frontIndex ^ backIndex) > 0) curDiff += (elements[rightIndex] - q[middleIndex]);
                q[backIndex] = elements[rightIndex];
                backIndex++;
                if (middleIndex < (backIndex + frontIndex) / 2) middleIndex++;
            }
            rightIndex++;
        }
        curDiff -= (q[middleIndex] - q[frontIndex]);
        frontIndex++;
        if (middleIndex < (backIndex + frontIndex) / 2) middleIndex++;
        leftIndex++;
    }
    return (int) maxDiff;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long r, l, b; cin >> r >> l >> b;
    for (int i = 0; i < r; i++) cin >> X[i];
    cout << besthub(r, l, X, b) << '\n';
}