#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int N, cnt = 0;
vector<int> heights;

int visibility(vector<int> heights, int m) {
    double highestSlope = -0x7FFFFFFF;
    int vis = 0;
    for (int i = m + 1; i < heights.size(); i++) {
        double slope = (double) (heights[i] - heights[m]) / (double) (i - m);
        if (slope > highestSlope) {
            highestSlope = slope;
            vis++;
        }
    }
    
    highestSlope = -0x7FFFFFFF;
    for (int i = m - 1; i >= 0; i--) {
        double slope = - ((double) (heights[i] - heights[m]) / (double) (i - m));
        if (slope > highestSlope) {
            highestSlope = slope;
            vis++;
        }
    }
    
    return vis;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    while (cnt < 10) {
        cin >> N;
        heights.clear();
        for (int i = 0, x; i < N; i++) { cin >> x; heights.push_back(x); }
        int maxVis = 0, maxM = 0;
        for (int i = 0; i < N; i++) {
            int curr = visibility(heights, i);
            if (curr > maxVis) { maxM = i; maxVis = curr; }
        }
        cout << maxM + 1 << '\n';
        cnt++;
    }
    return 0;
}