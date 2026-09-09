#include <iostream>
using namespace std;

int main() {
    int fishDepth[4], deltaA[4];
    int i, counter = 0;

    for(i = 0; i < 4; i++) {
        cin >> fishDepth[i];
    }

    for(i = 0; i < 3; i++) {
        if(fishDepth[i+1] > fishDepth[i]) {
            deltaA[i] = 1;
        } else if(fishDepth[i+1] < fishDepth[i]) {
            deltaA[i] = -1;
        } else {
            deltaA[i] = 0;
        }
        counter = counter + deltaA[i];
    }

    bool alleq = true;
    for(i=1; i<3; i++) {
        if(deltaA[0] != deltaA[i]) {
            alleq = false;
            break;
        }
    }

    if(counter == 3) {
        cout << "Fish Rising";
    } else if(counter == -3) {
        cout << "Fish Diving";
    } else if (alleq == true) {
        cout << "Fish At Constant Depth";
    } else if (alleq == false) {
        cout << "No Fish";
    }
    return 0;
}