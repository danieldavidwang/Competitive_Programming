#include <iostream>
#include <vector>
using namespace std;

struct p {
    long long x, y;

    bool operator<(const p& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }

    friend ostream& operator<<(ostream& os, const p& p) {
        os << p.x << " " << p.y;
        return os;
    }
};

long long crossProduct(const p& o, const p& a, const p& b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool dosegsInt(const vector<p>& seg1, const vector<p>& seg2) {
    auto& a = seg1[0];
    auto& b = seg1[1];
    auto& c = seg2[0];
    auto& d = seg2[1];

    return max(a.x, b.x) >= min(c.x, d.x) &&
           max(c.x, d.x) >= min(a.x, b.x) &&
           max(a.y, b.y) >= min(c.y, d.y) &&
           max(c.y, d.y) >= min(a.y, b.y) &&
           crossProduct(a, c, d) * crossProduct(b, c, d) <= 0;
}

int main() {
    p start, end;
    cin >> start.x >> start.y >> end.x >> end.y;

    int segCount, ans = 0;
    cin >> segCount;

    while (segCount--) {
        int pCount;
        cin >> pCount;

        vector<p> segps(pCount);
        for (auto& p : segps)
            cin >> p.x >> p.y;

        for (int i = 0; i < pCount; i++)
            if (dosegsInt({segps[(i + 1) % pCount], segps[i]}, {start, end})) {
                ans++;
                break;
            }
    }

    cout << ans << '\n';

    return 0;
}