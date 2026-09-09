#pragma GCC optimize (2)

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int angle1, angle2, angle3;
    
    cin >> angle1;
    cin >> angle2;
    cin >> angle3;

    if(angle1 + angle2 + angle3 != 180) {
        cout << "Error";
    } else {
        if (angle1 == angle2 && angle1 == angle3) {
            cout << "Equilateral";
        } else if (angle1 == angle2 || angle2 == angle3 || angle1 == angle3) {
            cout << "Isosceles";
        } else if (angle1 != angle2 && angle2 != angle3 && angle1 != angle3) {
            cout << "Scalene";
        }
    }
    return 0;
}