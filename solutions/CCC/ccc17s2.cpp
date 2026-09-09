#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    bool isOdd = false;
    cin >> N;

    int tides[N];
    int lowTides[N/2];
    int highTides[N/2];

    for (int i = 0; i < N; i++) {
        cin >> tides[i];
    }

    int n = sizeof(tides) / sizeof(tides[0]);
    sort(tides, tides + n);

    if (N%2 == 1) {
        isOdd = true;
    }

    for (int j = 0; j < N/2; j++) {
        lowTides[j] = tides[j];
    }

    if (isOdd == true) {
        N = N-1;
        for (int k = 0; k < N/2; k++) {
            highTides[k] = tides[k+(N/2)+1];
        }
    } else {
        for (int k = 0; k < N/2; k++) {
            highTides[k] = tides[k+(N/2)];
        }
    }

    if (isOdd == true) {
        cout << tides[(N+1)/2] << " ";
        for (int l = N/2; l > 0; l--) {
            cout << highTides[(N/2)-l] << " ";
            cout << lowTides[l-1] << " ";
        }
    } else {
        for (int l = N/2; l > 0; l--) {
            cout << lowTides[l-1] << " ";
            cout << highTides[(N/2)-l] << " ";
        }
    }
}