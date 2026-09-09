#pragma GCC optimize (2)

#include <iostream>
#include <cmath>
using namespace std;

string previousdirection = "";

string determineFirst (int num) {
    int newNum = num / 1000;
    if ((newNum / 10 + newNum % 10) == 0) {
        return previousdirection;
    } if ((newNum / 10 + newNum % 10) % 2 == 1) {
        return "left";
    } else {
        return "right";
    }
}

int determineSecond (int num) {
    return num % 1000;
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int directions[100000];

    for(int i = 0; i < 1000; i++) {
        cin >> directions[i];
        if (directions[i] == 99999) {
            break;
        }
        previousdirection = determineFirst(directions[i]);
        cout << previousdirection << " ";
        cout << determineSecond(directions[i]) << "\n";
    }
}