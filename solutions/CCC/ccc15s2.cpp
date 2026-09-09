#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;
int A;
int J;
unordered_map<int, char> m;

int main() {
    cin >> J;
    cin >> A;
    int count = 0;

    for(int i=0;i<J;i++) {
        char size;
        cin >> size;
        m[i+1] = size;
    }
    for(int j=0;j<A;j++) {
        char sizeA; int number;
        cin >> sizeA; cin >> number;
        char jj = m[number];
        if(sizeA >= jj) {
            count++;
            m[number] = 'Z';
        }
    }
    cout << count;
    return 0;
}