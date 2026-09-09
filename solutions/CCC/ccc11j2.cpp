#pragma GCC optimize (2)

#include <iostream>
#include <cmath>
using namespace std;

int counterA = 0;

int determine(int h, int t) {
    int valueToreturn = -1;
    for(int i = 1; i < t + 1; i++) {
        counterA++;
        int A = -6*pow(i, 4) + h*pow(i, 3) + 2*pow(i, 2) + i;
        if (A <= 0) {
            valueToreturn = counterA;
            break;
        }
    }
    return valueToreturn;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int time, humidity;

    cin >> humidity;
    cin >> time;

    int result = determine(humidity, time);

    if (result == -1) {
        cout << "The balloon does not touch ground in the given time.";
    } else {
        cout << "The balloon first touches ground at hour: " << endl << result;
    }
}