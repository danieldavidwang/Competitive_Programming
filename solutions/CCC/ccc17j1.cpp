#pragma GCC optimize (2)

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int cordX, cordY;

    cin >> cordX;
    cin >> cordY;

    if (cordX > 0 && cordY > 0) {
        cout << "1";
    } else if (cordX < 0 && cordY > 0) {
        cout << "2";
    } else if (cordX < 0 && cordY < 0) {
        cout << "3";
    } else {
        cout << "4";
    }
    return 0;
}