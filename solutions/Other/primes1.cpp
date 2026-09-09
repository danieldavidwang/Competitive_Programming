#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int N; cin >> N;
   
    int num = 1;
    int counter = 0;
   
    while (counter < N) {
        bool isPrime = true;
        num++;
        for (int z = 2; z <= sqrt(num); z++){
            if (num % z == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            cout << num << "\n";
            counter ++;
        }
    }
    return 0;
}