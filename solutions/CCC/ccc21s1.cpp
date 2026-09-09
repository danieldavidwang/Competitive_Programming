#pragma GCC optimize (2)
#include <iostream>
using namespace std;

double calculate(double num1, double num2, double num3) {
    return ((num1+num3))*num2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    double val;
    cin >> N;

    double sum = 0.0;
    double heights[N+1], widths[N];

    for(int i = 0; i < N+1; i++) {
        cin >> val;
        heights[i] = val;
    }

    for(int k = 0; k < N; k++) {
        cin >> val;
        widths[k] = val;
    }

    for(int j = 0; j < N; j++) {
        sum += calculate(heights[j], widths[j], heights[j+1]);
    }
    printf("%.1f", sum/2);
}