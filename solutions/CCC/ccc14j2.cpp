#pragma GCC optimize (2)

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int total; 
    int counterA = 0, counterB = 0;
    char input[15];

    cin >> total;

    for(int i = 0; i < total; i++) {
        cin >> input[i];
        if(input[i] == 'A') {
            counterA++;
        } else if(input[i] == 'B') {
            counterB++;
        }
    }

    if(counterA > counterB) {
        cout << 'A';
    } else if (counterB > counterA){
        cout << 'B';
    } else {
        cout << "Tie";
    }
    return 0;
}