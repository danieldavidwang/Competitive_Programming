#include <iostream>

using namespace std;

int main() {
    int N; cin >> N;
    int counter = 0;

    char S_choices[N];
    char C_choices[N];

    for (int i = 0; i < N; i++) {
        cin >> S_choices[i];
    }

    for (int j = 0; j < N; j++) {
        cin >> C_choices[j];
    }

    for (int k = 0; k < N; k++) {
        if (S_choices[k] == C_choices[k]) {
            counter++;
        }
    }
    cout << counter;
}