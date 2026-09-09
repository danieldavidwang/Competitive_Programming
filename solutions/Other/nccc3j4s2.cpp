#include <bits/stdc++.h>
using namespace std;
const short MM = 101;
int N, nums[MM][MM], median[MM];
int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> nums[i][j];
    for (int i = 0; i < N; i++) {
        sort(nums[i], nums[i] + N);
        median[i] = nums[i][N / 2];
    }
    sort(median, median + N);
    cout << median[N/2] << '\n';
}