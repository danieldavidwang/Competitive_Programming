#pragma GCC optimize (2)

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int square[4][4];
    int row[4];
    int column[4];
    
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> square[i][j];
        }
    }   

    for(int i = 0; i < 4; i++) {
        row[i] = 0;
        for(int j = 0; j < 4; j++) {
            row[i] = row[i] + square[i][j];
        }
    }

    for(int i = 0; i < 4; i++) {
        column[i] = 0;
        for(int j = 0; j < 4; j++) {
            column[i] = column[i] + square[j][i];
        } 
    }
    bool magic = true;

    for(int i = 0; i < 4; i++) {
        if(row[i] != row[0]) {
            magic = false;
            break;
        } else {
            continue;
        }
    }

    for(int i = 0; i < 4 && magic == true; i++) {
        if(column[i] != column[0]) {
            magic = false;
            break;
        } else {
            continue;
        }
    }

    if (magic) {
        cout << "magic\n";
    } else {
        cout << "not magic\n";
    }
    return 0;
}