#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

bool isClockwise(const Point &o, const Point &a, const Point &b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x) < 0;
}

vector<Point> convexHull(vector<Point> points) {
    int n = points.size();
    if (n <= 2)
        return points;
    
    sort(points.begin(), points.end(), [](const Point &a, const Point &b) {
        return a.x != b.x ? a.x < b.x : a.y < b.y;
    });

    vector<Point> hull;
    for (int i = 0; i < n; ++i) {
        while (hull.size() >= 2 && !isClockwise(hull[hull.size() - 2], hull[hull.size() - 1], points[i]))
            hull.pop_back();
        hull.push_back(points[i]);
    }

    int t = hull.size() + 1;
    for (int i = n - 2; i >= 0; --i) {
        while (hull.size() >= t && !isClockwise(hull[hull.size() - 2], hull[hull.size() - 1], points[i]))
            hull.pop_back();
        hull.push_back(points[i]);
    }

    hull.pop_back();
    return hull;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i)
        cin >> points[i].x >> points[i].y;
    
    vector<Point> convexHullPoints = convexHull(points);

    long long area = 0;
    for (int i = 0; i < convexHullPoints.size(); ++i)
        area += (long long)(convexHullPoints[i].x) * convexHullPoints[(i + 1) % convexHullPoints.size()].y -
                (long long)(convexHullPoints[i].y) * convexHullPoints[(i + 1) % convexHullPoints.size()].x;

    cout << abs(area) / 100 << '\n';

    return 0;
}