#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <iostream>

#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int main() {
    int W; 
    int N; 
    int counter = 0;

    scan(W);
    scan(N);

    int trains[N];

    for (int i = 0; i < N; i++) {
        scan(trains[i]);
    }

    for (int j = 0; j < N-3; j++) {
        if (trains[j] + trains[j+1] + trains[j+2] + trains[j+3] > W) {
            break;
        } else {
            counter++;
        }
    }

    if (trains[0] <= W) {
        counter++;
    } if ((trains[1] + trains[0]) <= W) {
        counter++;
    } if ((trains[2] + trains[1] + trains[0]) <= W) {
        counter++;
    } 
    cout << counter;
}