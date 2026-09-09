#include <bits/stdc++.h>
using namespace std;
int n, W;

struct item {
    int value;
    int weight;
};

int solve(int W, vector<item> &items) {
    int n = items.size();
    int dp[W+1];
    for (int w = 0; w <= W; w++) dp[w] = 0;
    for (int i = 0; i < n; i++)
        for (int w = W; w >= items[i].weight; w--)
            dp[w] = max(dp[w], items[i].value + dp[w - items[i].weight]);
    
    return dp[W];
}

int main() {
    cin >> n >> W;
    vector<item> items(n);
    for (int i = 0; i < n; i++) { cin >> items[i].value >> items[i].weight; }
    cout << solve(W, items);
    return 0;
}