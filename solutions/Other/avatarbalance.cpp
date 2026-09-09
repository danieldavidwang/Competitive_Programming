#pragma GCC optimize (2)
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N;
vector<int> nums;

int solveMin(vector<int> const &S, int n, int S1, int S2) {
    if (n < 0) return abs(S1 - S2);
    int sol1 = solveMin(S, n - 1, S1 + S[n], S2);
    int sol2 = solveMin(S, n - 1, S1, S2 + S[n]);
    return min(sol1, sol2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    while(N--) {
        int x; cin >> x;
        nums.push_back(x);
    }
    int n = nums.size();
    cout << solveMin(nums, n - 1, 0, 0) << '\n';
}