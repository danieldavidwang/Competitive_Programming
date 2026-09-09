#pragma GCC optimize (2)
#include <iostream>
using namespace std;
int input[4];
int output[5][5];
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

void distance() {
    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < 5; i++) {
            if (i == j) output[i][j] = 0;
            else if (i > j) output[i][j] = output[i-1][j] + input[i-1];
            else if (i < j) output[i][j] = output[j][i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    for (int i = 0; i < 4; i++)
        scan(input[i]);
    distance();
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++)
            cout << output[i][j] << " ";
        cout << '\n';
    }
}