#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <iostream>
#include <algorithm>

using namespace std;

int N; 
int speedD[1000];
int speedP[1000];
int sum = 0;

int findMax () {
    for (int i = 0; i < N; i++) {
        if (speedD[i] > speedP[N-i-1]) sum += speedD[i];
        else sum += speedP[N-i-1];
    }
    return sum;
}

int findMin () {
    for (int i = 0; i < N; i++) {
        if (speedD[i] > speedP[i]) sum += speedD[i];
        else sum += speedP[i];
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int x;
    int qType; cin >> qType;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> speedD[i];
    } for (int j = 0; j < N; j++) {
        cin >> speedP[j];
    }

    sort(speedD, speedD + N);
    sort(speedP, speedP + N);

    if (qType == 1) x = findMin();
    else x = findMax();
    
    cout << x;
}