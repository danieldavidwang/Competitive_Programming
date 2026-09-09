#pragma GCC optimize (2)
#include <iostream>
using namespace std;

int table[2][2] = {{1,2}, {3,4}};

void calculate(char reflect) {
    if(reflect == 'H') {
        int w = table[0][0];
        int y = table[0][1];

        table[0][0] = table[1][0];
        table[0][1] = table[1][1];

        table[1][0] = w;
        table[1][1] = y;
    } else if (reflect == 'V') {
        int w = table[0][0];
        int x = table[1][0];

        table[0][0] = table[0][1];
        table[1][0] = table[1][1];

        table[0][1] = w;
        table[1][1] = x;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string N; cin >> N;
    int size = N.length();

    char reflection[size];

    for(int i = 0; i < size; i++) {
        reflection[i] = N[i];
        calculate(reflection[i]);
    }
    
    cout << table[0][0] << " " << table[0][1] << "\n";
    cout << table[1][0] << " " << table[1][1];
}