#include <iostream>

using namespace std;

int main() {
    int N; cin >> N;
    bool valid = true;

    string names1[N];
    string names2[N];

    for (int i = 0; i < N; i++) {
        cin >> names1[i];
    }

    for (int j = 0; j < N; j++) {
        cin >> names2[j];
    }

    for (int k = 0; k < N; k++) {
        if (names1[k] == names2[k]) {
            valid = false;
            break;
        } else {
            for (int l = 0; l < N; l++) {
                if ((names1[l] == names2[k]) && (names2[l] != names1[k])) {
                    valid = false;
                    break;
                }
            }
        }
    }

    if (valid) {
        cout << "good";
    } else {
        cout << "bad";
    }
}