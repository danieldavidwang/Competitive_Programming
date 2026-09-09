#include <iostream>
using namespace std;

int main() {
    int N;
    int dayNum = 0;
    int sumSW = 0;
    int sumSE = 0;

    cin >> N;

    int sw[N];
    int se[N];

    for (int i = 0; i < N; i++) {
        cin >> sw[i];
    }

    for (int j = 0; j < N; j++) {
        cin >> se[j];
    }

    for (int k = 1; k < N+1; k++) {
        sumSW += sw[k-1];
        sumSE += se[k-1];
        if (sumSW == sumSE) {
            dayNum = k;
        }
    }
    cout << dayNum;
}