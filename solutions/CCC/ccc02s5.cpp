#include <bits/stdc++.h>
using namespace std;
double w, h, xx, yy;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> w >> h >> xx >> yy;
    double slope = yy / (w - xx);

    for (int i = 1; i <= 1e6+1; i++) {
        double y = slope * (i * w - xx);
        double x = (i * h) / slope + xx;

        double a = (int)((y - h / 2) / h + 1) * h;
        double b = (int)((x - w / 2) / w + 1) * w;

        if (std::abs(a - y) < 5 || std::abs(b - x) < 5) {
            if (std::abs(a - y) < 5)
                cout << i - 1 + static_cast<int>(y / h) - (std::abs(a - y) < 1e-2) << endl;
            else
                cout << i - 1 + static_cast<int>(x / w) - (std::abs(b - x) < 1e-2) << endl;

            return 0;
        }
    }

    cout << "0\n";
    return 0;
}