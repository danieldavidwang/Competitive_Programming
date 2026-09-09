#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int n, k, minn;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k;
    int nums[n];
    for (int i = 0; i < n; i++) cin >> nums[i];
    int x = sizeof(nums) / sizeof(nums[0]);
    sort(nums, nums + x);
    minn = nums[0];
    for (int i = 0; i < k; i++) nums[i] = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0 && nums[i] < 2*minn) {
            cout << nums[i] << '\n';
            return 0;
        }
    }
    cout << 2*minn << '\n';
}