#include <iostream>
using namespace std;

int main () {
    int A3, A2, A1, B3, B2, B1;

    cin >> A3;
    cin >> A2;
    cin >> A1;
    cin >> B3;
    cin >> B2;
    cin >> B1;

    if (3*A3 + 2*A2 + A1 > 3*B3 + 2*B2 + B1) {
        cout << "A";
    } else if (3*A3 + 2*A2 + A1 < 3*B3 + 2*B2 + B1) {
        cout << "B";
    } else {
        cout << "T";
    }
}