#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
    int K; cin >> K;
    string word;

    unordered_map<string, char> letters;

    for (int i = 0; i < K; i++) {
        char c; cin >> c;
        string s; cin >> s;

        letters[s] = c;
    }
    cin >> word;

    for (int j = 0; j < word.length(); j++) {
        string determine;
        bool Found = false;

        determine = word[j];

        while (!Found) {
            if (letters.find(determine) == letters.end()) {
                j=j+1;
                determine += word[j];
            } else {
                Found = true;
            }
        }
        cout << letters[determine];
    }
}