#include <iostream>
using namespace std;

int main() {
    int small, medium, large, Sums;

    cin >> small;
    cin >> medium;
    cin >> large;

    Sums = small + 2 * medium + 3 * large;
    if (Sums >= 10) {
        cout << "happy";
    } else {
        cout << "sad";
    }
}