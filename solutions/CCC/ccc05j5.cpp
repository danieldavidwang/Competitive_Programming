#include <bits/stdc++.h>
using namespace std;
string word; bool validW;

bool check(string word, vector<string> gudWs) {
    validW = 0;
    if (find(gudWs.begin(), gudWs.end(), word) != gudWs.end()) validW = 1;
    else if (word[0] == 'B' && word[word.length()-1] == 'S' && word.substr(1, word.length()-2) != "" && check(word.substr(1, word.length()-2), gudWs)) validW = 1;
    else if (word == "A") validW = 1;
    for (int i = 1; i < word.length()-1 && !validW; i++) if (word[i] == 'N' && check(word.substr(0, i), gudWs) && check(word.substr(i+1, word.length()-1), gudWs)) validW = 1;
    if (validW) gudWs.push_back(word);
    return validW;
}

bool check2(string word) { vector<string> gudWs; return check(word, gudWs); }

int main() {
    cin >> word;
    
    while (word != "X") {
        if (check2(word)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
        cin >> word;
    }
}