#include <iostream>
using namespace std;

int main() {
    int speedLim, userSpeed, over;

    cin >> speedLim;
    cin >> userSpeed;

    over = userSpeed - speedLim;

    if (speedLim >= userSpeed) {
        cout << "Congratulations, you are within the speed limit!";
    } else if (over > 0 && over < 21) {
        cout << "You are speeding and your fine is $100."; 
    } else if (over > 20 && over < 31) {
        cout << "You are speeding and your fine is $270."; 
    } else {
        cout << "You are speeding and your fine is $500."; ;
    }
    return 0;
}