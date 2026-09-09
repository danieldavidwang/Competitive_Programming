#pragma GCC optimize (2)

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    char input[100];
    int i;
    bool isTrue = true;

    cin >> input;

    for (i = 0; i < 100; i++) {
        
        if(input[i] == 0) {
            break;
        }
        if (input[i] != 'I' && input[i] != 'O' && input[i] != 'S' && 
            input[i] != 'H' && input[i] != 'Z' && input[i] != 'X' && input[i] != 'N') {
            isTrue = false;
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}