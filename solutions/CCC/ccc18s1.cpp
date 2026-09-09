#pragma GCC optimize (2)
#include <iostream>
#include <algorithm>
using namespace std;

double calculateSize(long num1, long num3) {
    return ((num3-num1)/2.0);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N;
    double min = 1000000000000;
    cin >> N;

    long villages[N];

    for(int i = 0; i < N; i++) {
        cin >> villages[i];
    }
    int n = sizeof(villages) / sizeof(villages[0]);
    sort(villages, villages + n);
    for(int j = 1; j < N-1; j++) {
        double x = calculateSize(villages[j-1], villages[j+1]);
        if(x < min) min = x;
    }
    printf("%.1f", min);
}