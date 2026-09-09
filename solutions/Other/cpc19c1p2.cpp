#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, R;
    cin >> n >> R;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) cin >> heights[i];
    sort(heights.begin(), heights.end());
    int max_items = 0, start = 0;
    
    for (int end = 0; end < n; ++end) {
        while (heights[end] - heights[start] > R) ++start;
        max_items = max(max_items, end - start + 1);
    }
    
    cout << max_items << '\n';
    return 0;
}