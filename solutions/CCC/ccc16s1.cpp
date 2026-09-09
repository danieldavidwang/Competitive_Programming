#include <iostream>
#include <map>

using namespace std;

int main() {
    string line1, line2;
    bool isAnagram = true;

    cin >> line1;
    cin >> line2;

    map<char, int> freq1;
    map<char, int> freq2;

    for (int i = 0; i < line1.length(); i++) {
        char letter = line1[i];
        
        if (freq1.find(letter) == freq1.end()) {
            freq1[letter] = 0;
        }
        freq1[letter]++;
    }

    for (int j = 0; j < line2.length(); j++) {
        char letter2 = line2[j];
        
        if (letter2 == '*') {
            continue;
        }
        
        if (freq2.find(letter2) == freq2.end()) {
            freq2[letter2] = 0;
        }
        freq2[letter2]++;
        
        if (freq2[letter2] > freq1[letter2]) {
            isAnagram = false;
            break;
        }
    }

    if (isAnagram == false) {
        cout << "N";
    } else {
        cout << "A";
    }
}