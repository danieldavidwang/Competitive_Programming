#include <iostream>
#define max(a,b) ((a) > (b) ? (a) : (b))
using namespace std;
int pre[251][251];

int main() {
    int w, h, n, maxSum = 0;
    cin >> w >> h >> n;

    for (int y = 1; y <= h; y++) {
        for (int x = 1; x <= w; x++) {
            cin >> pre[x][y];
            pre[x][y] += pre[x - 1][y] + pre[x][y - 1] - pre[x - 1][y - 1];
        }
    }

    for (int y = 1; y <= h; y++) {
        for (int x = 1; x <= w; x++) {
            for (int yy = 1; yy <= y; yy++) {
                int tempSum = pre[x][y] - pre[x][y - yy] - pre[max(x - (n / yy), 0)][y] + pre[max(x - (n / yy), 0)][y - yy];
                maxSum = max(maxSum, tempSum);
            }
        }
    }

    cout << maxSum << '\n';
    return 0;
}