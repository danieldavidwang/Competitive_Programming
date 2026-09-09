#include <iostream>
using namespace std;

int main () {
    int L, numofChar;
    char character;
    cin >> L;

    for (int i = 0; i < L; i++) {
        cin >> numofChar;
        cin >> character;
        for (int j = 0; j < numofChar; j++) {
            cout << character;
        }
        cout << endl;
    }
    return 0;
}