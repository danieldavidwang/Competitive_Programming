#pragma GCC optimize (2)

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int P, N, R, newN;
    int result = 1;
    int counter = 0;

    cin >> P;
    cin >> N;
    cin >> R;

    result = N;
    newN = N;

    for (int i = 0; i < 10000000; i++) {
        newN = newN * R;
        result = result + newN;

        counter ++;
        if (result > P) {
            break;
        }
    }
    cout << counter;
}