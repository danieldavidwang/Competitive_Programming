#include <iostream>
using namespace std;

int main() {
    int t, s, h;
    cin >> t >> s >> h;
    
    for (int x = 0; x < t; x++) {
        cout << "*";
        for (int y = 0; y < s; y++) cout << " ";
        cout << "*";
        for (int y = 0; y < s; y++) cout << " ";
        cout << "*\n";
    }
    
    for (int x = 0; x < 2 * s + 3; x++) cout << "*";
    cout << "\n";
    
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < 1 + s; x++) cout << " ";
        cout << "*\n";
    }
    
    return 0;
}