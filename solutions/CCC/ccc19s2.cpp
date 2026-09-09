#pragma GCC optimize (2)
#include <iostream>
#include <cmath>
using namespace std;

int isPrime(int num) {
    int x = sqrt(num);

    for (int i = 2; i < x + 1; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    int average[T];

    for(int j = 0; j < T; j++) {
        cin >> average[j];
    }

    for (int a = 0; a < T; a++) {
        int b = isPrime(average[a]);

        if (b == 1) {
            cout << average[a] << " " << average[a] << endl;
        } else {
            for (int c = 1; c < (average[a] - 2); c++) {
                int check1 = average[a] - c;
                int check2 = average[a] + c;

                int e = isPrime(check1);
                int f = isPrime(check2);
                
                if (e == 1 && f == 1) {
                    cout << check1 << " " << check2 << endl;
                    break;
                }
            }
        }
    }
}