#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <iostream>
using namespace std;

char scaler[3][3] = {
    {'*','x','*'},
    {' ','x','x'},
    {'*',' ','*'}
};

void outputK(char c, int num) {
    for(int i=0;i<num;i++) {
        cout << c;
    }
}

void outputLine(char line[], int num) {
    for(int j = 0; j < 3; j++) {
        outputK(line[j], num);
    }
    cout << '\n';
}

int main() {
    int k;
    cin >> k;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < k; j++) {
            outputLine(scaler[i],k);
        }
    }
    return 0;
}