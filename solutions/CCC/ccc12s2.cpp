#include <iostream>
#include <vector>

using namespace std;

string number;
int roman[10000];

int main() {
    int fVal = 0;  
    cin >> number;

    int arab[number.length()];

    for (int i = 0; i < number.length(); i += 2) {
        arab[i] = number[i] - '0';
        char c = number[i+1];

        if (c == 'I') {
            roman[i] = 1;
        } else if (c == 'V') {
            roman[i] = 5;
        } else if (c == 'X') {
            roman[i] = 10;
        } else if (c == 'L') {
            roman[i] = 50;
        } else if (c == 'C') {
            roman[i] = 100;
        } else if (c == 'D') {
            roman[i] = 500;
        } else if (c == 'M') {
            roman[i] = 1000;
        }
    }
 
    // for (int j = 0; j < number.length(); j += 2) {
    //     cout << "arab is: " << arab[j] << endl;
    //     cout << "roman is: " << roman[j] << endl;
    // }

    for (int j = 0; j < number.length(); j += 2) {
        if (roman[j+2] > roman[j]) {
            fVal -= arab[j] * roman[j];
        } else {
            fVal += arab[j] * roman[j];
        }
    }
    cout << fVal;
}