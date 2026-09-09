#include <iostream>
using namespace std;

int main() {
    int phoneNum[4];

    for(int i = 0; i < 4; i++) {
        cin >> phoneNum[i];
        // cout << phoneNum[i];
    }
    if ((phoneNum[0] == 8 || phoneNum[0] == 9) && (phoneNum[3] == 8 || phoneNum[3] == 9) && (phoneNum[1] == phoneNum[2])) {
        cout << "ignore";
    } else {
        cout << "answer";
    }
    return 0;
}