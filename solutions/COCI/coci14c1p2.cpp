#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
struct Point { int x, y; };

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i) cin >> points[i].x >> points[i].y;

    int minX = numeric_limits<int>::max(), minY = numeric_limits<int>::max();
    int maxX = numeric_limits<int>::min(), maxY = numeric_limits<int>::min();

    for (const auto& point : points) {
        minX = min(minX, point.x);
        minY = min(minY, point.y);
        maxX = max(maxX, point.x);
        maxY = max(maxY, point.y);
    }

    int sideLength = max(maxX - minX, maxY - minY);
    cout << sideLength * sideLength << '\n';
    return 0;
}