#include <iostream>

using namespace std;

int findDistinct(int num) {
    bool Found = false;
    
    while (!Found) {
        bool satisfy = true;
        num += 1;
        string str = to_string(num);

        for (int i = 0; i < str.length(); i++) {
            for (int j = 0; j < str.length(); j++) {
                if (str[i] == str[j] && i != j) {
                    satisfy = false;
                }
            }
        }
        if (satisfy) {
            Found = true;
        }
    }
    return num; 
}

int main() {
    int Y;
    cin >> Y;

    int x = findDistinct(Y);

    cout << x;
}