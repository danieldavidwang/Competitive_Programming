#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int N, hi, lo, per;

void findLo() {
    int temp = int(sqrt(N));
    while (N % temp != 0) {
        temp--;
    }
    lo = temp;
}

int main() {
    while (true) {
        scanf("%d", &N);
        if (!N) break;
        findLo();
        hi = N/lo;
        per = 2*(lo+hi);
        printf("Minimum perimeter is %d with dimensions %d x %d\n", per, lo, hi);
    }
}