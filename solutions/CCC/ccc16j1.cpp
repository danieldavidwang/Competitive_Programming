#include <iostream>
using namespace std;

int main() {
    char line1, line2, line3, line4, line5, line6;
    int counter = 0;

    cin >> line1;
    cin >> line2;
    cin >> line3;
    cin >> line4;
    cin >> line5;
    cin >> line6;

    if(line1 == 'W') {
        counter++;
    } if (line2 == 'W') {
        counter++;
    } if (line3 == 'W') {
        counter++;
    } if (line4 == 'W') {
        counter++;
    } if (line5 == 'W') {
        counter++;
    } if (line6 == 'W') {
        counter++;
    } if (counter == 5 || counter == 6) {
        cout << "1";
    } else if (counter == 3 || counter == 4) {
        cout << "2";
    } else if (counter == 1 || counter == 2) {
        cout << "3";
    } else {
        cout << "-1";
    }
}