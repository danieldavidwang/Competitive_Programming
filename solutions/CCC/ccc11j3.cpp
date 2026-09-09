#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <iostream>
using namespace std;

int num1, num2;
int counter = 2;
int last1, last2;

int sumac(int n) {
    if (n < 0) {
        return counter;
    } else {
        int next = last2 - n;
        counter++;
        last1 = last2;
        last2 = n;
        sumac(next); 
    }
    return counter;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> num1;
    cin >> num2;

    last1 = num1;
    last2 = num2;

    int result = sumac(num1-num2);
    cout << result;
}