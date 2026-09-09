#include <bits/stdc++.h>

using namespace std;

bool determine(char a, char b) {
    if ((a == 'p' && b == 'q') || (a == 'q' && b == 'p')) {
        return true;
    } if ((a == 'b' && b == 'd') || (a == 'd' && b == 'b')) {
        return true;
    }
    return false;
}

int main() {
    string s;
    
    getline(cin, s);
    cout << "Ready" << endl;
    
    while (s[0] != ' ' && s[1] != ' ') {
        bool z = determine(s[0], s[1]);
        if (z == true) {
            cout << "Mirrored pair" << endl;
        } else {
            cout << "Ordinary pair" << endl;
        }
        getline(cin, s);
    }
}