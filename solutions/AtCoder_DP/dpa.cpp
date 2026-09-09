#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+1;
int N, minCost[MM], heights[MM];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> heights[i];
    minCost[0] = 0; minCost[1] = abs(heights[1]-heights[0]);
    for (int i = 2; i < N; i++)
        minCost[i] = min(minCost[i-1]+abs(heights[i]-heights[i-1]), minCost[i-2]+abs(heights[i]-heights[i-2]));
    cout << minCost[N-1];
}