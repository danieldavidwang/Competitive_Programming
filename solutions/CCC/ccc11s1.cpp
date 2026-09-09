#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    string lines;

    map<char, int> freq;

    cin.ignore();

    for (int i = 0; i < N; i++) {
        getline(cin, lines);
        
        for (int j = 0; j < lines.length(); j++) {
            char letter = lines[j];

            if (freq.find(letter) == freq.end()) {
                freq[letter] = 0;
            }
            freq[letter]++;
        }
    }

    if (freq['t'] + freq['T'] > freq['s'] + freq['S']) {
        cout << "English";
    } else {
        cout << "French";
    }
}