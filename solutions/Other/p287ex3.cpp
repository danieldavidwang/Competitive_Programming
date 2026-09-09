#include <bits/stdc++.h>
using namespace std;
int N;
float x, minn = INT_MAX;

int main() {
    cin >> N;
    while (N--) {
        cin >> x;
        if (x < minn) minn = x;
    }
    printf("%.2f\n", minn);
}