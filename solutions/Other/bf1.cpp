#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    int nums[n];
    
    for (int i = 0; i < n; i++) cin >> nums[i];
    
    for(int i = 1; i < n; i++) {
        int j = i;
        while ((j > 0) && (nums[j] < nums[j-1])) {
            int temp = nums[j];
            nums[j] = nums[j-1];
            nums[j-1] = temp;
            j--;
        }
    }
    for (int i = 0; i < n; i++) cout << nums[i] << endl;
}