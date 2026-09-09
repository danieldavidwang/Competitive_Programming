#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    // cout << "line :" << line << endl;

    int pos1 = line.find(":-)");
    int countHappy = 0;
    string leftOverString = line;
    while(pos1 >= 0) {
        leftOverString = leftOverString.substr(pos1 + 3);
        pos1 = leftOverString.find(":-)");
        countHappy++;
        // cout << "pos1:" << pos1 << endl;
    }
    // cout << "happy :" << countHappy << endl;

    int pos2 = line.find(":-(");
    int countSad = 0;
    string leftOverString2 = line;
    while(pos2 >= 0) {
        leftOverString2 = leftOverString2.substr(pos2 + 3);
        pos2 = leftOverString2.find(":-(");
        countSad++;
    }
    // cout << "sad :" << countSad << endl;

    if (countSad > countHappy) {
        cout << "sad";
    } else if (countSad == 0 && countHappy == 0) {
        cout << "none";
    } else if (countHappy == countSad) {
        cout << "unsure";
    } else {
        cout << "happy";
    }
    return 0;
}