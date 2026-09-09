#pragma GCC optimize (2)

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int N; scanf("%d", &N);
    int counter = 0;

    for(int i = 0; i <= 1000000; i++) {
        int total = i*5;
        int remain = N - total;
        if (remain < 0) break;
        else if (remain >= 0 && remain % 4 == 0) counter++;
    }
    printf("%d", counter);
}