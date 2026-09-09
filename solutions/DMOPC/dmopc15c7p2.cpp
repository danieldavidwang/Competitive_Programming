#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string input;
    getline(cin, input);

    istringstream iss(input);
    int wordCount = 0;
    string word;

    while (iss >> word) {
        wordCount++;
    }

    cout << wordCount << endl;

    return 0;
}