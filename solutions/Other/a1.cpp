#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int main() {
    int N; cin >> N;
    cin.ignore();

    for (int i = 0; i < N; i++) {
        int removeIndex; cin >> removeIndex;
        string word; getline(cin, word);
        // cin.ignore();
        
        int x = word.length()-1;

        if (removeIndex >= 1 && removeIndex <= x) {
            string newWord = word.substr(0, removeIndex) + word.substr(removeIndex+1, x-1);
            cout << i+1 << newWord << endl;
        }
    }
}