#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int N, total;
string nums;
bool ans;

void check() {
    total = 0; ans = false;
    for (int i = 0; i < nums.length(); i++) {
        total += int(nums[i])%3;
    }
    if (total%3==0) ans = true;
    else ans = false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nums;
        check();
        ans? cout << "yes\n" : cout << "no\n";
    }
    return 0;
}