#include <iostream>
using namespace std;

int main() {
    int numofAuct;
    string name[1000];
    int bidNum[1000];
    cin >> numofAuct;

    for (int i = 0; i < numofAuct; i++) {
        cin >> name[i];
        cin >> bidNum[i];
    }
    int maxbidNum = bidNum[0];
    int maxIndex;
    for (int j = 0; j < numofAuct; j++) {
        if(bidNum[j] > maxbidNum) {
            maxbidNum = bidNum[j];
            maxIndex = j;
        }
    }
    cout << name[maxIndex];
}