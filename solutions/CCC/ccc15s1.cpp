#include <iostream>
#include <vector>

using namespace std;

int main() {
    int K; cin >> K;
    int numVals;
    int sum = 0;
    vector<int> numbers;

    for (int i = 0; i < K; i++) {
        cin >> numVals;
        numbers.push_back(numVals);
    }
    
    for (long j = K-1; j > 0; j--) {
        // cout << "j is" << j << "    number j is:" << numbers[j] << endl;
        if (numbers[j] == 0) {
            long y = j;

            // cout << "the number being earsed is: " << numbers[y] << endl;
            numbers.erase(numbers.begin()+y);

            while (numbers[y-1] == 0) {
                y--;
                if(y <= 0)
                    break;
            }
            
            // cout << "the number non-zero being earsed is: " << numbers[y-1] << endl;
            numbers.erase(numbers.begin()+(y-1));
            j=j-1;
        }
    }

    for (auto itr = numbers.begin(); itr != numbers.end(); itr++) {
        sum += (*itr);
    }
    cout << sum;
}